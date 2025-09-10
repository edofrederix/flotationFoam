#include "dispersedInterception.H"
#include "particleModel.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace particleTransferModels
{
    defineTypeNameAndDebug(dispersedInterception, 0);
    addToRunTimeSelectionTable
    (
        particleTransferModel,
        dispersedInterception,
        dictionary
    );
}
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::particleTransferModels::dispersedInterception::
dispersedInterception
(
    const particleModel& model,
    const dictionary& dict
)
:
    dispersedParticleTransferModel(model, dict),
    efficiency_
    (
        dispersedInterceptionEfficiency::New(*this, dict).ptr()
    )
{}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::particleTransferModels::dispersedInterception::K(volScalarField& N) const
{
    label i = Foam::flotationSystem::sectionNum(N);
    const scalar pi(constant::mathematical::pi);

    const dimensionedScalar dp(model_.system().distribution()[i]);

    const volScalarField d(interface_.dispersed().d());
    const volVectorField V(model_[i].V());

    const volVectorField& U = interface_.dispersed().U();

    return 0.25*pi*sqr(d + dp)*mag(U-V)*efficiency_->E(N);
}

// ************************************************************************* //
