#include "attachmentEfficiencyModel.H"
#include "flotationSystem.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
    defineTypeNameAndDebug(attachmentEfficiencyModel, 0);
    defineRunTimeSelectionTable(attachmentEfficiencyModel, dictionary);
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::attachmentEfficiencyModel::attachmentEfficiencyModel
(
    const dictionary& dict,
    const fvMesh& mesh,
    flotationSystem& system,
    const bool registerObject
)
:
    efficiencyModel(dict, mesh, system, registerObject, typeName)
{
    induction_.set
    (
        inductionTimeModel::New
        (
            dict.subDict("inductionTime"),
            mesh,
            system,
            registerObject
        ).ptr()
    );
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::attachmentEfficiencyModel::~attachmentEfficiencyModel()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

// ************************************************************************* //
