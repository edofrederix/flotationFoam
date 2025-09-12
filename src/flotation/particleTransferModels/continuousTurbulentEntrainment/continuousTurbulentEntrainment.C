#include "continuousTurbulentEntrainment.H"
#include "particleModel.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace particleTransferModels
{
    defineTypeNameAndDebug(continuousTurbulentEntrainment, 0);
    addToRunTimeSelectionTable
    (
        particleTransferModel,
        continuousTurbulentEntrainment,
        dictionary
    );
}
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::particleTransferModels::continuousTurbulentEntrainment::
continuousTurbulentEntrainment
(
    const particleModel& model,
    const dictionary& dict
)
:
    continuousParticleTransferModel(model, dict),
    rate_
    (
        continuousTurbulentEntrainmentRate::New(*this, dict).ptr()
    )
{}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::particleTransferModels::continuousTurbulentEntrainment::K(volScalarField& N) const
{
    return rate_->R(N);
}

// ************************************************************************* //
