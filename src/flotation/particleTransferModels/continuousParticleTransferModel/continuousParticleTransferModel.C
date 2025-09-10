#include "continuousParticleTransferModel.H"
#include "particleModel.H"
#include "flotationSystem.H"

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::particleTransferModels::continuousParticleTransferModel::
continuousParticleTransferModel
(
    const particleModel& model,
    const dictionary& dict
)
:
    particleTransferModel(model),
    interface_(model.phase(), model.otherPhase())
{}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //


// ************************************************************************* //
