#include "continuousBrownianEntrainment.H"
#include "particleModel.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace particleTransferModels
{
    defineTypeNameAndDebug(continuousBrownianEntrainment, 0);
    addToRunTimeSelectionTable
    (
        particleTransferModel,
        continuousBrownianEntrainment,
        dictionary
    );
}
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::particleTransferModels::continuousBrownianEntrainment::
continuousBrownianEntrainment
(
    const particleModel& model,
    const dictionary& dict
)
:
    continuousParticleTransferModel(model, dict),
    Sh_
    (
        SherwoodNumber::New
        (
            model.system().mesh(),
            word(dict.lookup("Sh"))
        ).ptr()
    )
{}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::particleTransferModels::continuousBrownianEntrainment::K
(
    volScalarField& N
)
const
{
    label i = Foam::flotationSystem::sectionNum(N);
    const scalar pi(constant::mathematical::pi);

    const volScalarField d(interface_.dispersed().d());
    const volScalarField D(model_[i].D());
    const volScalarField nu(interface_.dispersed().fluidThermo().nu());

    // Reynolds number of the flow inside the dispersed phase induced by the
    // continuous phase. Note that this is not the same as the Reynolds number
    // of the interface (which would be based on the continuous phase
    // viscosity).

    const volScalarField Re(interface_.magUr()*d/nu);

    const volScalarField Sc(nu/D);
    const volScalarField Sh(Sh_->Sh(Re,Sc));

    return pi*Sh*d*D;
}

// ************************************************************************* //
