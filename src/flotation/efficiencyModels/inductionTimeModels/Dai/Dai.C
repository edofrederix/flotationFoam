#include "Dai.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace inductionTimeModels
{
    defineTypeNameAndDebug(Dai, 0);
    addToRunTimeSelectionTable(inductionTimeModel, Dai, dictionary);
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::inductionTimeModels::Dai::Dai
(
    const dictionary& dict,
    const fvMesh& mesh,
    flotationSystem& system,
    const bool registerObject
)
:
    inductionTimeModel(dict, mesh, system, registerObject),
    A_(readScalar(dict.lookup("A"))),
    B_(readScalar(dict.lookup("B")))
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::inductionTimeModels::Dai::~Dai()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::scalar
Foam::inductionTimeModels::Dai::t
(
    const Foam::label& sectionI
) const
{
    return A_*Foam::pow(system_.distribution()[sectionI].value(), B_);
}

// ************************************************************************* //
