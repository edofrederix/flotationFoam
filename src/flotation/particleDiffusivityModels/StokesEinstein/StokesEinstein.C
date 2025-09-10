#include "StokesEinstein.H"
#include "particleModel.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"
#include "fundamentalConstants.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace particleDiffusivityModels
{
    defineTypeNameAndDebug(StokesEinstein, 0);
    addToRunTimeSelectionTable
    (
        particleDiffusivityModel,
        StokesEinstein,
        dictionary
    );
}
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::particleDiffusivityModels::StokesEinstein::StokesEinstein
(
    particleModel& model,
    const dictionary& dict
)
:
    particleDiffusivityModel(model, dict),
    f_(dict.lookupOrDefault<scalar>("f", 1.0))
{}

// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::particleDiffusivityModels::StokesEinstein::~StokesEinstein()
{}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void Foam::particleDiffusivityModels::StokesEinstein::correct()
{
    const scalar pi(constant::mathematical::pi);

    const dimensionedScalar kb(constant::physicoChemical::k);
    const volScalarField mu(model_.phase().fluidThermo().mu());
    const volScalarField T(model_.phase().thermo().T());

    forAll(model_, i)
    {
        const dimensionedScalar dp(model_.system().distribution()[i]);

        model_[i].D() = f_*kb*T/(3.0*pi*mu*dp);
    }
}

// ************************************************************************* //
