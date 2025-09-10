#include "localEquilibrium.H"
#include "particleModel.H"
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
    addToRunTimeSelectionTable
    (
        particleVelocityModel,
        localEquilibrium,
        dictionary
    );
}
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::particleVelocityModels::localEquilibrium::localEquilibrium
(
    particleModel& model,
    const dictionary& dict
)
:
    particleVelocityModel(model, dict)
{}

// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::particleVelocityModels::localEquilibrium::~localEquilibrium()
{}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void Foam::particleVelocityModels::localEquilibrium::correct()
{
    const dimensionedScalar& rhop = model_.system().rho();

    const surfaceScalarField gAf
    (
        model_.system().mesh().lookupObject<uniformDimensionedVectorField>("g")
      & model_.system().mesh().Sf()
    );

    const surfaceScalarField& phi = model_.phase().phi();

    const surfaceScalarField rho(fvc::interpolate(model_.phase().rho()));

    const surfaceScalarField nu
    (
        fvc::interpolate
        (
            model_.phase().fluidThermo().nu()
        )
    );

    const scalar steadyState =
        dict_.lookupOrDefault<Switch>("steadyState", false);

    forAll(model_, i)
    {
        const dimensionedScalar dp(model_.system().distribution()[i]);

        const surfaceScalarField tau(rhop/rho*sqr(dp)/(18.0*nu));
        const surfaceScalarField ddt(fvc::ddt(phi));

        model_[i].phi() =
            phi + ((1.0 - rho/rhop)*gAf - (1.0 - steadyState)*ddt)*tau;
    }
}

// ************************************************************************* //
