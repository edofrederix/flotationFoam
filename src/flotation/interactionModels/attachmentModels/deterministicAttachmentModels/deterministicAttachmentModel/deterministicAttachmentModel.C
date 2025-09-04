#include "deterministicAttachmentModel.H"
#include "flotationSystem.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
    defineTypeNameAndDebug(deterministicAttachmentModel, 0);
    defineRunTimeSelectionTable(deterministicAttachmentModel, dictionary);
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::deterministicAttachmentModel::deterministicAttachmentModel
(
    const dictionary& dict,
    const fvMesh& mesh,
    flotationSystem& system,
    const bool registerObject
)
:
    attachmentModel(dict, mesh, system, registerObject, typeName)
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::deterministicAttachmentModel::~deterministicAttachmentModel()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

// ************************************************************************* //
