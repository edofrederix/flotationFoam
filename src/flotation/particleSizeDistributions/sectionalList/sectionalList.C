#include "sectionalList.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace particleSizeDistributions
{
    defineTypeNameAndDebug(sectionalList, 0);
    addToRunTimeSelectionTable(particleSizeDistribution, sectionalList, dictionary);
}
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::particleSizeDistributions::sectionalList::sectionalList
(
    const dictionary& dict,
    const fvMesh& mesh,
    const bool registerObject
)
:
    particleSizeDistribution(dict, mesh, registerObject)
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

Foam::particleSizeDistributions::sectionalList::~sectionalList()
{}

// ************************************************************************* //
