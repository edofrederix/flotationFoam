#include "localEquilibrium.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"
#include "fvc.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace particleVelocityModels
{
    defineTypeNameAndDebug(localEquilibrium, 0);
    addToRunTimeSelectionTable(particleVelocityModel, localEquilibrium, dictionary);
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::particleVelocityModels::localEquilibrium::localEquilibrium
(
    const dictionary& dict,
    const fvMesh& mesh,
    flotationSystem& system,
    const bool registerObject
)
:
    particleVelocityModel(dict, mesh, system, registerObject)
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::particleVelocityModels::localEquilibrium::~localEquilibrium()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void Foam::particleVelocityModels::localEquilibrium::update()
{
    const dimensionedScalar& rhop = system_.rho();
    const uniformDimensionedVectorField& g =
        system_.mesh().lookupObject<uniformDimensionedVectorField>("g");

    const volScalarField& rhol = system_.twoPhasePair().continuous().rho();
    const volVectorField& Ul = system_.twoPhasePair().continuous().U();
    const volScalarField nul(system_.twoPhasePair().continuous().thermo().nu());

    const scalar steadyState
    (
        dict_.lookupOrDefault<Switch>("steadyState", false) == true
      ? 1.0
      : 0.0
    );

    forAll(system_.freeParticles(), sectionI)
    {
        surfaceScalarField& phi = system_.freeParticles()[sectionI].phi();
        volVectorField& V = system_.freeParticles()[sectionI].V();

        const dimensionedScalar ds(system_.distribution()[sectionI]);

        tmp<volScalarField> ttau
        (
            new volScalarField
            (
                IOobject
                (
                    "tau",
                    mesh_.time().timeName(),
                    mesh_,
                    IOobject::NO_READ,
                    IOobject::NO_WRITE
                ),
                mesh_,
                dimensionedScalar("tau", dimTime, 0.0)
            )
        );

        volScalarField& tau = ttau.ref();

        tau = rhop/rhol * sqr(ds)/(18.0*nul);

        V = Ul + ((1.0 - rhol/rhop)*g - (1.0-steadyState)*fvc::ddt(Ul))*tau;

        V.correctBoundaryConditions();

        phi = fvc::flux(V);
    }
}

// ************************************************************************* //
