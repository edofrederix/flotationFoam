#include "monoDisperse.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace sectionalDistributions
{
    defineTypeNameAndDebug(monoDisperse, 0);
    addToRunTimeSelectionTable(sectionalDistribution, monoDisperse, dictionary);
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::sectionalDistributions::monoDisperse::monoDisperse
(
    const dictionary& dict,
    const fvMesh& mesh,
    const bool registerObject
)
:
    sectionalDistribution(dict, mesh, registerObject)
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

Foam::sectionalDistributions::monoDisperse::~monoDisperse()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //


// ************************************************************************* //
