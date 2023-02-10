#include "stabilizationEfficiencyModel.H"
#include "flotationSystem.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
    defineTypeNameAndDebug(stabilizationEfficiencyModel, 0);
    defineRunTimeSelectionTable(stabilizationEfficiencyModel, dictionary);
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::stabilizationEfficiencyModel::stabilizationEfficiencyModel
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

Foam::stabilizationEfficiencyModel::~stabilizationEfficiencyModel()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

// ************************************************************************* //
