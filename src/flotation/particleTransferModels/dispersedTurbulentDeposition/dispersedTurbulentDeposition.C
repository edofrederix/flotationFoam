#include "dispersedTurbulentDeposition.H"
#include "particleModel.H"
#include "flotationSystem.H"
#include "fvmSup.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace particleTransferModels
{
    defineTypeNameAndDebug(dispersedTurbulentDeposition, 0);
    addToRunTimeSelectionTable
    (
        particleTransferModel,
        dispersedTurbulentDeposition,
        dictionary
    );
}
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::particleTransferModels::dispersedTurbulentDeposition::
dispersedTurbulentDeposition
(
    const particleModel& model,
    const dictionary& dict
)
:
    dispersedParticleTransferModel(model, dict),
    rate_
    (
        dispersedTurbulentDepositionRate::New(*this, dict).ptr()
    )
{}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::particleTransferModels::dispersedTurbulentDeposition::K
(
    volScalarField& N
) const
{
    return rate_->R(N);
}

// ************************************************************************* //
