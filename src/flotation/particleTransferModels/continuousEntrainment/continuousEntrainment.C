#include "continuousEntrainment.H"
#include "particleModel.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace particleTransferModels
{
    defineTypeNameAndDebug(continuousEntrainment, 0);
    addToRunTimeSelectionTable
    (
        particleTransferModel,
        continuousEntrainment,
        dictionary
    );
}
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::particleTransferModels::continuousEntrainment::
continuousEntrainment
(
    const particleModel& model,
    const dictionary& dict
)
:
    continuousParticleTransferModel(model, dict),
    rate_
    (
        continuousEntrainmentRate::New(*this, dict).ptr()
    )
{}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::particleTransferModels::continuousEntrainment::K(volScalarField& N) const
{
    return rate_->R(N);
}

// ************************************************************************* //
