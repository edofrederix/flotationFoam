#include "YoonLuttrellStokesAttachment.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace attachmentEfficiencyModels
{
    defineTypeNameAndDebug(YoonLuttrellStokesAttachment, 0);
    addToRunTimeSelectionTable(attachmentEfficiencyModel, YoonLuttrellStokesAttachment, dictionary);
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::attachmentEfficiencyModels::YoonLuttrellStokesAttachment::YoonLuttrellStokesAttachment
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

Foam::attachmentEfficiencyModels::YoonLuttrellStokesAttachment::~YoonLuttrellStokesAttachment()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::attachmentEfficiencyModels::YoonLuttrellStokesAttachment::efficiency
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
                      - 3.0*Ub*ti / (db*(1.0/R(sectionI)+1.0))
                    )
                )
            )
        )
    );

    return tP;
}

// ************************************************************************* //
