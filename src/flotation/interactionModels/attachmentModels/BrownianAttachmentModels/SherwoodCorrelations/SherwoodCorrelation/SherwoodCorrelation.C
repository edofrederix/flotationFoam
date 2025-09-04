#include "SherwoodCorrelation.H"
#include "flotationSystem.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
    defineTypeNameAndDebug(SherwoodCorrelation, 0);
    defineRunTimeSelectionTable(SherwoodCorrelation, dictionary);
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::SherwoodCorrelation::SherwoodCorrelation
(
    const dictionary& dict,
    const fvMesh& mesh,
    flotationSystem& system
)
:
    mesh_(mesh),
    system_(system),
    dict_(dict)
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::SherwoodCorrelation::~SherwoodCorrelation()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

// ************************************************************************* //
