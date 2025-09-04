#include "infiniteSink.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace BrownianAttachmentModels
{
    defineTypeNameAndDebug(infiniteSink, 0);
    addToRunTimeSelectionTable(BrownianAttachmentModel, infiniteSink, dictionary);
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::BrownianAttachmentModels::infiniteSink::infiniteSink
(
    const dictionary& dict,
    const fvMesh& mesh,
    flotationSystem& system,
    const bool registerObject
)
:
    BrownianAttachmentModel(dict, mesh, system, registerObject)
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::BrownianAttachmentModels::infiniteSink::~infiniteSink()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::BrownianAttachmentModels::infiniteSink::rate
(
    const Foam::label& sectionI
) const
{
    const scalar pi(constant::mathematical::pi);

    tmp<volScalarField> tB(emptyRateField("Batt"));

    volScalarField& B = tB.ref();

    const volScalarField db(system_.twoPhasePair().dispersed().d());

    const volScalarField Ds
    (
        system_.BrownDiff().D(sectionI)
    );

    const volScalarField Re(system_.Re());
    const volScalarField Sc(system_.Sc(Ds));

    const volScalarField Sh(SherwoodCorrel_->Sh(Re,Sc));

    B = pi*Sh*db*Ds;

    return tB;
}

// ************************************************************************* //
