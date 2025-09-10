#include "particleModel.H"
#include "flotationSystem.H"
#include "fvm.H"
#include "fvc.H"
#include "fvModels.H"
#include "fvConstraints.H"

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::particleModel::particleModel
(
    flotationSystem& system,
    const phaseModel& phase
)
:
    PtrList<particleSection>(),
    system_(system),
    phase_(phase),
    dict_(system.subDict("particles_in_" + phase.name())),
    Sct_
    (
        "Sct",
        dimless,
        dict_.lookup("Sct")
    ),
    silent_(dict_.lookupOrDefault("silent", true)),
    sources_(dict_.lookup("models"), particleTransferModel::iNew(*this))
{
    // Create particle sections

    this->setSize(system.distribution().size());

    forAll(*this, i)
    {
        this->set(i, new particleSection(i+1, *this));
    }

    // Set the particle velocity model

    velocityModel_.set
    (
        particleVelocityModel::New(*this, dict_.subDict("velocity")).ptr()
    );

    // Set the Brownian diffusivity model

    diffusivityModel_.set
    (
        particleDiffusivityModel::New(*this, dict_.subDict("diffusivity")).ptr()
    );

    // Correct models

    diffusivityModel_->correct();
    velocityModel_->correct();
}

// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::particleModel::~particleModel()
{}

// * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * * //

const Foam::phaseModel& Foam::particleModel::otherPhase() const
{
    return
       &system_.interface().phase1() == &phase_
      ? system_.interface().phase2()
      : system_.interface().phase1();
}

Foam::particleModel& Foam::particleModel::otherParticleModel()
{
    return
       &system_.interface().phase1() == &phase_
      ? system_.model2()
      : system_.model1();
}

Foam::List<Foam::solverPerformance> Foam::particleModel::solve()
{
    diffusivityModel_->correct();
    velocityModel_->correct();

    const fvModels& fvModels(fvModels::New(system_.mesh()));

    const fvConstraints& fvConstraints
    (
        fvConstraints::New(system_.mesh())
    );

    const volScalarField nut(turbulence().nut());

    List<solverPerformance> perfs(this->size());

    const int levelCache = Info.level;

    forAll(*this, i)
    {
        volScalarField& N = this->operator[](i).N();
        volScalarField& M = otherParticleModel()[i].N();

        const volScalarField& D = this->operator[](i).D();
        const surfaceScalarField& phi = this->operator[](i).phi();

        const volScalarField nuEff("nuEff", D + nut/Sct_);

        fvScalarMatrix R(N, N.dimensions()*dimVolume/dimTime);

        // Add sources belonging to this phase' particle model

        forAll(sources_, j)
        {
            R += sources_[j].R(N);
        }

        // Subtract sources belonging to the other phase' particle model

        forAll(otherParticleModel().sources(), j)
        {
            R -= (otherParticleModel().sources()[j].R(M) & M);
        }

        fvScalarMatrix NEqn
        (
            fvm::ddt(N)
          + fvm::div(phi, N, "div(phi,N)")
          ==
            fvm::laplacian(nuEff, N)
          + R
          + fvModels.source(N)
        );

        fvConstraints.constrain(NEqn);

        if (silent_)
        {
            Info.level = 0;
        }

        perfs[i] = NEqn.solve();

        if (silent_)
        {
            Info.level = levelCache;
        }

        fvConstraints.constrain(N);
    }

    return perfs;
}

const Foam::phaseCompressible::momentumTransportModel&
Foam::particleModel::turbulence() const
{
    return
        system_.mesh().lookupObject<phaseCompressible::momentumTransportModel>
        (
            IOobject::groupName
            (
                momentumTransportModel::typeName,
                phase_.name()
            )
        );
}

const Foam::phaseCompressible::momentumTransportModel&
Foam::particleModel::otherPhaseTurbulence() const
{
    return
        system_.mesh().lookupObject<phaseCompressible::momentumTransportModel>
        (
            IOobject::groupName
            (
                momentumTransportModel::typeName,
                otherPhase().name()
            )
        );
}

// ************************************************************************* //
