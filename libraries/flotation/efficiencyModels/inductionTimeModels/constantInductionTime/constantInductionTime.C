#include "constantInductionTime.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace inductionTimeModels
{
    defineTypeNameAndDebug(constantInductionTime, 0);
    addToRunTimeSelectionTable(inductionTimeModel, constantInductionTime, dictionary);
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::inductionTimeModels::constantInductionTime::constantInductionTime
(
    const dictionary& dict,
    const fvMesh& mesh,
    flotationSystem& system,
    const bool registerObject
)
:
    inductionTimeModel(dict, mesh, system, registerObject),
    t_(readScalar(dict.lookup("t")))
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::inductionTimeModels::constantInductionTime::~constantInductionTime()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::scalar
Foam::inductionTimeModels::constantInductionTime::t
(
    const Foam::label& sectionI
) const
{
    return t_;
}

// ************************************************************************* //
