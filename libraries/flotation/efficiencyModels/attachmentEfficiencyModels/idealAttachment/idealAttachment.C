#include "idealAttachment.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace attachmentEfficiencyModels
{
    defineTypeNameAndDebug(idealAttachment, 0);
    addToRunTimeSelectionTable(attachmentEfficiencyModel, idealAttachment, dictionary);
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::attachmentEfficiencyModels::idealAttachment::idealAttachment
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

Foam::attachmentEfficiencyModels::idealAttachment::~idealAttachment()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::attachmentEfficiencyModels::idealAttachment::efficiency
(
    const Foam::label& sectionI
) const
{
    tmp<volScalarField> tP(emptyEfficiencyField("Patt"));

    volScalarField& P = tP.ref();

    P = dimensionedScalar(P.name(), P.dimensions(), 1.0);

    return tP;
}

// ************************************************************************* //
