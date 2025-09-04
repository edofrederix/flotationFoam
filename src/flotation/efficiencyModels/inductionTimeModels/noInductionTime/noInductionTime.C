#include "noInductionTime.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace inductionTimeModels
{
    defineTypeNameAndDebug(noInductionTime, 0);
    addToRunTimeSelectionTable(inductionTimeModel, noInductionTime, dictionary);
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::inductionTimeModels::noInductionTime::noInductionTime
(
    const dictionary& dict,
    const fvMesh& mesh,
    flotationSystem& system,
    const bool registerObject
)
:
    inductionTimeModel(dict, mesh, system, registerObject)
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::inductionTimeModels::noInductionTime::~noInductionTime()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::scalar
Foam::inductionTimeModels::noInductionTime::t
(
    const Foam::label& sectionI
) const
{
    return 0.0;
}

// ************************************************************************* //
