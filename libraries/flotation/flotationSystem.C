#include "flotationSystem.H"
#include "fvm.H"
#include "fvc.H"
#include "fvModels.H"
#include "fvConstraints.H"

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::flotationSystem::flotationSystem
(
    const phaseSystem& fluid,
    const fvMesh& mesh
)
:
    IOdictionary
    (
        IOobject
        (
            "flotationProperties",
            mesh.time().constant(),
            mesh,
            IOobject::MUST_READ_IF_MODIFIED,
            IOobject::NO_WRITE
        )
    ),
    fluid_(fluid),
    mesh_(mesh),
    rho_
    (
        "rho",
        dimDensity,
        *this
    ),
    Sct_
    (
        "Sct",
        dimless,
        *this
    )
{
    // Ordered phase pair

    const word continuousPhaseName(lookup("continuousPhaseName"));
    const word dispersedPhaseName(lookup("dispersedPhaseName"));

    label cPhase = -1;
    label dPhase = -1;

    forAll(fluid_.phases(), i)
    {
        if (fluid_.phases()[i].name() == continuousPhaseName)
        {
            cPhase = i;
        }
    }

    if (cPhase == -1)
    {
        FatalErrorInFunction
            << "Continuous phase " << continuousPhaseName << " not found"
            << abort(FatalError);
    }

    forAll(fluid_.phases(), i)
    {
        if (fluid.phases()[i].name() == dispersedPhaseName)
        {
            dPhase = i;
        }
    }

    if (cPhase == -1)
    {
        FatalErrorInFunction
            << "Dispersed phase " << dispersedPhaseName << " not found"
            << abort(FatalError);
    }

    twoPhasePair_.set
    (
        new dispersedPhaseInterface
        (
            fluid_.phases()[dPhase],
            fluid_.phases()[cPhase]
        )
    );

    // Set sectional distribution

    distribution_.set
    (
        sectionalDistribution::New
        (
            subDict("sectionalDistribution"),
            mesh
        ).ptr()
    );

    // Create particle sections

    freeParticles_.setSize(distribution().size());
    capturedParticles_.setSize(distribution().size());

    forAll(distribution(), sectionI)
    {
        freeParticles_.set
        (
            sectionI,
            new freeParticleSection(sectionI+1, *this)
        );

        capturedParticles_.set
        (
            sectionI,
            new capturedParticleSection(sectionI+1, *this)
        );
    }

    // Set the particle velocity model

    particleVelocity_.set
    (
        particleVelocityModel::New
        (
            subDict("particleVelocityModel"),
            mesh,
            *this
        ).ptr()
    );

    // Set the Brownian diffusivity model

    BrownDiff_.set
    (
        BrownianDiffusivityModel::New
        (
            subDict("BrownianDiffusivityModel"),
            mesh,
            *this
        ).ptr()
    );

    // Set the efficiency models

    colEff_.set
    (
        collisionEfficiencyModel::New
        (
            subDict("efficiencyModels").subDict("collisions"),
            mesh,
            *this
        ).ptr()
    );

    attEff_.set
    (
        attachmentEfficiencyModel::New
        (
            subDict("efficiencyModels").subDict("attachment"),
            mesh,
            *this
        ).ptr()
    );

    stabEff_.set
    (
        stabilizationEfficiencyModel::New
        (
            subDict("efficiencyModels").subDict("stabilization"),
            mesh,
            *this
        ).ptr()
    );

    // Set the interaction models

    detAttachRate_.set
    (
        deterministicAttachmentModel::New
        (
            subDict("interactionModels").subDict("attachment").subDict("deterministic"),
            mesh,
            *this
        ).ptr()
    );

    stochAttachRate_.set
    (
        stochasticAttachmentModel::New
        (
            subDict("interactionModels").subDict("attachment").subDict("stochastic"),
            mesh,
            *this
        ).ptr()
    );

    BrownAttachRate_.set
    (
        BrownianAttachmentModel::New
        (
            subDict("interactionModels").subDict("attachment").subDict("Brownian"),
            mesh,
            *this
        ).ptr()
    );

    stochDetachRate_.set
    (
        stochasticDetachmentModel::New
        (
            subDict("interactionModels").subDict("detachment").subDict("stochastic"),
            mesh,
            *this
        ).ptr()
    );

    // Set the efficiency fields

    Pcol_.setSize(distribution().size());
    Patt_.setSize(distribution().size());
    Pstab_.setSize(distribution().size());

    forAll(distribution(), sectionI)
    {
        Pcol_.set
        (
            sectionI,
            new volScalarField
            (
                IOobject
                (
                    IOobject::groupName("Pcol", Foam::name(sectionI+1)),
                    mesh.time().timeName(),
                    mesh,
                    IOobject::NO_READ,
                    IOobject::NO_WRITE
                ),
                mesh,
                dimensionedScalar("Pcol", dimless, 0.0)
            )
        );

        Patt_.set
        (
            sectionI,
            new volScalarField
            (
                IOobject
                (
                    IOobject::groupName("Patt", Foam::name(sectionI+1)),
                    mesh.time().timeName(),
                    mesh,
                    IOobject::NO_READ,
                    IOobject::NO_WRITE
                ),
                mesh,
                dimensionedScalar("Patt", dimless, 0.0)
            )
        );

        Pstab_.set
        (
            sectionI,
            new volScalarField
            (
                IOobject
                (
                    IOobject::groupName("Pstab", Foam::name(sectionI+1)),
                    mesh.time().timeName(),
                    mesh,
                    IOobject::NO_READ,
                    IOobject::NO_WRITE
                ),
                mesh,
                dimensionedScalar("Pstab", dimless, 0.0)
            )
        );
    }
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::flotationSystem::~flotationSystem()
{}


// * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * * //

void Foam::flotationSystem::solve()
{
    particleVelocity_->update();

    const volScalarField nut(continuousTurbulence().nut());

    const scalar pi(constant::mathematical::pi);

    const volScalarField db(twoPhasePair().dispersed().d());

    const volScalarField B
    (
        twoPhasePair().dispersed()*6.0 / (pi*Foam::pow(db, 3.0))
    );

    // Compute bubble loading parameter (only once per time step)

    tmp<volScalarField> tbeta
    (
        new volScalarField
        (
            IOobject
            (
                "beta",
                mesh_.time().timeName(),
                mesh_,
                IOobject::NO_READ,
                IOobject::NO_WRITE
            ),
            mesh_,
            dimensionedScalar("beta", dimless, 0.0)
        )
    );

    volScalarField& beta = tbeta.ref();

    const dimensionedScalar SB(B.name(), B.dimensions(), SMALL);

    forAll(distribution(), sectionI)
    {
        volScalarField& Nc = capturedParticles_[sectionI].N();

        const dimensionedScalar ds(distribution()[sectionI]);

        beta += (Nc*sqr(ds) / (2.0*sqr(db)*stabilise(B,SB)));
    }

    beta.max(dimensionedScalar(beta.name(), beta.dimensions(), 0.0));
    beta.min(dimensionedScalar(beta.name(), beta.dimensions(), 1.0));

    const volScalarField F(B*(1.0-beta));

    // Read solver controls

    const dictionary& NControls = mesh_.solution().solverDict("Nsystem");

    const scalar tolerance(readScalar(NControls.lookup("tolerance")));

    const label minIter(NControls.lookupOrDefault<label>("minIter", 0));
    const label maxIter(NControls.lookupOrDefault<label>("maxIter", 1000));

    const Switch silent(NControls.lookupOrDefault<Switch>("silent", true));

    const fvModels& fvModels(fvModels::New(mesh_));
    const fvConstraints& fvConstraints
    (
        fvConstraints::New(mesh_)
    );

    forAll(distribution(), sectionI)
    {
        volScalarField& Nf = freeParticles_[sectionI].N();
        volScalarField& Nc = capturedParticles_[sectionI].N();

        const surfaceScalarField& phif = freeParticles_[sectionI].phi();
        const surfaceScalarField& phic = capturedParticles_[sectionI].phi();

        surfaceScalarField& Phif = freeParticles_[sectionI].Phi();
        surfaceScalarField& Phic = capturedParticles_[sectionI].Phi();

        const volScalarField D(BrownDiff_().D(sectionI) + nut/Sct_);

        const volScalarField Datt(detAttachRate_().rate(sectionI));
        const volScalarField Satt(stochAttachRate_().rate(sectionI));
        const volScalarField Batt(BrownAttachRate_().rate(sectionI));

        const volScalarField Sdet(stochDetachRate_().rate(sectionI));

        Pcol_[sectionI] = colEff_().efficiency(sectionI);
        Patt_[sectionI] = attEff_().efficiency(sectionI);
        Pstab_[sectionI] = stabEff_().efficiency(sectionI);

        const volScalarField Katt
        (
            Batt
          + (Datt+Satt)
          * Pcol_[sectionI]*Patt_[sectionI]*Pstab_[sectionI]
        );

        const volScalarField Kdet
        (
            Sdet*(1.0-Pstab_[sectionI])
        );

        const int levelCache = Info.level;

        scalar r(0.0);
        scalar r0(0.0);

        label iter;

        for (iter = 0; iter < maxIter; iter++)
        {
            fvScalarMatrix NfEqn
            (
                fvm::ddt(Nf)
              + fvm::div(phif, Nf, "div(phi,Nf)")
              ==
                fvm::laplacian(D,Nf)
              + fvc::Sp(Kdet, Nc)
              - fvm::Sp(Katt*F, Nf)
              + fvModels.source(Nf)
            );

            fvScalarMatrix NcEqn
            (
                fvm::ddt(Nc)
              + fvm::div(phic, Nc, "div(phi,Nc)")
              ==
                fvc::Sp(Katt*F, Nf)
              - fvm::Sp(Kdet, Nc)
              + fvModels.source(Nc)
            );

            NfEqn.relax();
            NcEqn.relax();

            fvConstraints.constrain(NfEqn);
            fvConstraints.constrain(NcEqn);

            if (silent)
            {
                Info.level = 0;
            }

            const scalar rf(NfEqn.solve().initialResidual());
            const scalar rc(NcEqn.solve().initialResidual());

            fvConstraints.constrain(Nf);
            fvConstraints.constrain(Nc);

            if (silent)
            {
                Info.level = levelCache;
            }

            r = max(rf,rc);

            if (iter == 0)
            {
                r0 = r;
            }

            if ((r < tolerance && iter >= minIter-1) || iter >= maxIter-1)
            {
                // Store effective fluxes

                Phif = NfEqn.flux();
                Phic = NcEqn.flux();

                break;
            }

        }

        Info << "flotationSystem: Solving for section " << sectionI+1
             << ", Initiual residual = " << r0
             << ", Final residual = " << r
             << ", No Iterations = " << iter << endl;
    }
}


bool Foam::flotationSystem::read()
{
    if (regIOobject::read())
    {
        return true;
    }
    else
    {
        return false;
    }
}

const Foam::phaseCompressible::momentumTransportModel&
Foam::flotationSystem::continuousTurbulence() const
{
    return
        mesh_.lookupObject<phaseCompressible::momentumTransportModel>
        (
            IOobject::groupName
            (
                momentumTransportModel::typeName,
                twoPhasePair().continuous().name()
            )
        );
}

// ************************************************************************* //
