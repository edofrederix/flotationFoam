#include "dispersedParticleTransferModel.H"
#include "particleModel.H"
#include "flotationSystem.H"
#include "fvmSup.H"

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::particleTransferModels::dispersedParticleTransferModel::
dispersedParticleTransferModel
(
    const particleModel& model,
    const dictionary& dict
)
:
    particleTransferModel(model),
    interface_(model.otherPhase(), model.phase())
{}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::fvScalarMatrix>
Foam::particleTransferModels::dispersedParticleTransferModel::R
(
    volScalarField& N
) const
{
    const scalar pi(constant::mathematical::pi);

    return
       -fvm::Sp
        (
            this->K(N)*interface_.dispersed()*6.0
          / (pi*pow3(interface_.dispersed().d())),
            N
        );
}

// ************************************************************************* //
