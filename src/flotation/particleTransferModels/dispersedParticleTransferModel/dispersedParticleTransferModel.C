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
{
    const phaseSystem& fluid = model.system().fluid();

    const dictionary& blendingDict =
        fluid.subDict("blending").found("particleTransfer")
      ? fluid.subDict("blending").subDict("particleTransfer")
      : fluid.subDict("blending").subDict("default");

    blending_.set
    (
        blendingMethod::New
        (
            "particleTransfer",
            blendingDict,
            interface_
        ).ptr()
    );
}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::fvScalarMatrix>
Foam::particleTransferModels::dispersedParticleTransferModel::R
(
    volScalarField& N
) const
{
    const scalar pi(constant::mathematical::pi);

    // Only activate when the first phase (i.e. the other phase) is considered
    // as dispersed

    const volScalarField blending
    (
        blending_->f1DispersedIn2
        (
            interface_.fluid().phases()
           .PtrList<phaseModel>::convert<const volScalarField>()
        )
    );

    return
       -fvm::Sp
        (
            blending
          * this->K(N)
          * 6.0*interface_.dispersed()
          / (pi*pow3(interface_.dispersed().d())),
            N
        );
}

// ************************************************************************* //
