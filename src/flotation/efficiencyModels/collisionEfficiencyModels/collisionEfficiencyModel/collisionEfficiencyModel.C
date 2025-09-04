#include "collisionEfficiencyModel.H"
#include "flotationSystem.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
    defineTypeNameAndDebug(collisionEfficiencyModel, 0);
    defineRunTimeSelectionTable(collisionEfficiencyModel, dictionary);
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::collisionEfficiencyModel::collisionEfficiencyModel
(
    const dictionary& dict,
    const fvMesh& mesh,
    flotationSystem& system,
    const bool registerObject
)
:
    efficiencyModel(dict, mesh, system, registerObject, typeName)
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::collisionEfficiencyModel::~collisionEfficiencyModel()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

// ************************************************************************* //
