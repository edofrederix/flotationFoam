#include "BrownianAttachmentModel.H"
#include "flotationSystem.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
    defineTypeNameAndDebug(BrownianAttachmentModel, 0);
    defineRunTimeSelectionTable(BrownianAttachmentModel, dictionary);
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::BrownianAttachmentModel::BrownianAttachmentModel
(
    const dictionary& dict,
    const fvMesh& mesh,
    flotationSystem& system,
    const bool registerObject
)
:
    attachmentModel(dict, mesh, system, registerObject, typeName)
{
    SherwoodCorrel_.set
    (
        SherwoodCorrelation::New
        (
            dict.subDict("SherwoodCorrelation"),
            mesh,
            system
        ).ptr()
    );
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::BrownianAttachmentModel::~BrownianAttachmentModel()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

// ************************************************************************* //
