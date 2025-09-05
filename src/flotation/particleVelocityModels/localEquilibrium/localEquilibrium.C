#include "localEquilibrium.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"
#include "fvc.H"
#include "uniformDimensionedFields.H"

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

    const surfaceScalarField gAf
    (
        system_.mesh().lookupObject<uniformDimensionedVectorField>("g")
      & system_.mesh().Sf()
    );

    const surfaceScalarField& phi =
        system_.twoPhasePair().continuous().phi();

    const surfaceScalarField rho
    (
        fvc::interpolate
        (
            system_.twoPhasePair().continuous().rho()
        )
    );

    const surfaceScalarField nu
    (
        fvc::interpolate
        (
            system_.twoPhasePair().continuous().fluidThermo().nu()
        )
    );

    const scalar steadyState =
        dict_.lookupOrDefault<Switch>("steadyState", false);

    forAll(system_.freeParticles(), sectionI)
    {
        const dimensionedScalar d(system_.distribution()[sectionI]);

        const surfaceScalarField tau(rhop/rho*sqr(d)/(18.0*nu));
        const surfaceScalarField ddt(fvc::ddt(phi));

        system_.freeParticles()[sectionI].phi() =
            phi + ((1.0 - rho/rhop)*gAf - (1.0 - steadyState)*ddt)*tau;
    }
}

// ************************************************************************* //
