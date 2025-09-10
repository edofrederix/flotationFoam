#include "monoDisperse.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace particleSizeDistributions
{
    defineTypeNameAndDebug(monoDisperse, 0);
    addToRunTimeSelectionTable(particleSizeDistribution, monoDisperse, dictionary);
}
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::particleSizeDistributions::monoDisperse::monoDisperse
(
    const dictionary& dict,
    const fvMesh& mesh,
    const bool registerObject
)
:
    particleSizeDistribution(dict, mesh, registerObject)
{
    this->clear();
    this->setSize(1);

    this->set
    (
        0,
        new dimensionedScalar
        (
            IOobject::groupName("ds", sectionName(0)),
            dimLength,
            readScalar(dict.lookup("diameter"))
        )
    );
}

// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::particleSizeDistributions::monoDisperse::~monoDisperse()
{}

// ************************************************************************* //
