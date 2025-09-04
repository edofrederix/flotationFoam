#include "SutherlandAttachment.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace attachmentEfficiencyModels
{
    defineTypeNameAndDebug(SutherlandAttachment, 0);
    addToRunTimeSelectionTable(attachmentEfficiencyModel, SutherlandAttachment, dictionary);
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::attachmentEfficiencyModels::SutherlandAttachment::SutherlandAttachment
(
    const dictionary& dict,
    const fvMesh& mesh,
    flotationSystem& system,
    const bool registerObject
)
:
    attachmentEfficiencyModel(dict, mesh, system, registerObject)
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::attachmentEfficiencyModels::SutherlandAttachment::~SutherlandAttachment()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::attachmentEfficiencyModels::SutherlandAttachment::efficiency
(
    const Foam::label& sectionI
) const
{
    tmp<volScalarField> tP(emptyEfficiencyField("Patt"));

    volScalarField& P = tP.ref();

    tmp<volScalarField> db(system_.twoPhasePair().dispersed().d());

    const volScalarField Ub(mag(system_.twoPhasePair().dispersed().U()));

    const dimensionedScalar ti
    (
        "ti",
        dimTime,
        induction_->t(sectionI)
    );

    const dimensionedScalar dp(system_.distribution()[sectionI]);

    P = clip
    (
        Foam::sqr
        (
            Foam::sin
            (
                2.0*Foam::atan
                (
                    Foam::exp
                    (
                      - 1.5*Ub*ti/(db+dp)
                    )
                )
            )
        )
    );

    return tP;
}

// ************************************************************************* //
