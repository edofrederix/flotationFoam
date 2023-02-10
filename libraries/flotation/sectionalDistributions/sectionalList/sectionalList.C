#include "sectionalList.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace sectionalDistributions
{
    defineTypeNameAndDebug(sectionalList, 0);
    addToRunTimeSelectionTable(sectionalDistribution, sectionalList, dictionary);
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::sectionalDistributions::sectionalList::sectionalList
(
    const dictionary& dict,
    const fvMesh& mesh,
    const bool registerObject
)
:
    sectionalDistribution(dict, mesh, registerObject)
{
    const scalarList diameters(dict.lookup("diameters"));

    this->clear();
    this->setSize(diameters.size());

    forAll(diameters, i)
    {
        this->set
        (
            i,
            new dimensionedScalar
            (
                IOobject::groupName("ds", sectionName(i)),
                dimLength,
                diameters[i]
            )
        );
    }
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::sectionalDistributions::sectionalList::~sectionalList()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //


// ************************************************************************* //
