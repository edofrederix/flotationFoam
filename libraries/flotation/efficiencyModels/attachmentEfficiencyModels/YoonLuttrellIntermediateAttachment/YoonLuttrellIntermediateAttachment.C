#include "YoonLuttrellIntermediateAttachment.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace attachmentEfficiencyModels
{
    defineTypeNameAndDebug(YoonLuttrellIntermediateAttachment, 0);
    addToRunTimeSelectionTable(attachmentEfficiencyModel, YoonLuttrellIntermediateAttachment, dictionary);
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::attachmentEfficiencyModels::YoonLuttrellIntermediateAttachment::YoonLuttrellIntermediateAttachment
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

Foam::attachmentEfficiencyModels::YoonLuttrellIntermediateAttachment::~YoonLuttrellIntermediateAttachment()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::attachmentEfficiencyModels::YoonLuttrellIntermediateAttachment::efficiency
(
    const Foam::label& sectionI
) const
{
    tmp<volScalarField> tP(emptyEfficiencyField("Patt"));

    volScalarField& P = tP.ref();

    tmp<volScalarField> Re(system_.twoPhasePair().Re());

    tmp<volScalarField> db(system_.twoPhasePair().dispersed().d());

    const volScalarField Ub(mag(system_.twoPhasePair().dispersed().U()));

    const dimensionedScalar ti
    (
        "ti",
        dimTime,
        induction_->t(sectionI)
    );

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
                      - (45.0+8.0*Foam::pow(Re,0.72))*Ub*ti
                      / (15.0*db*(1.0/R(sectionI)+1.0))
                    )
                )
            )
        )
    );

    return tP;
}

// ************************************************************************* //
