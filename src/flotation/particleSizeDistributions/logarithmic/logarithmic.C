#include "logarithmic.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace particleSizeDistributions
{
    defineTypeNameAndDebug(logarithmic, 0);
    addToRunTimeSelectionTable(particleSizeDistribution, logarithmic, dictionary);
}
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::particleSizeDistributions::logarithmic::logarithmic
(
    const dictionary& dict,
    const fvMesh& mesh,
    const bool registerObject
)
:
    particleSizeDistribution(dict, mesh, registerObject)
{
    const scalar dMin(readScalar(dict.lookup("dMin")));
    const scalar dMax(readScalar(dict.lookup("dMax")));
    const label N(readLabel(dict.lookup("N")));

    this->clear();
    this->setSize(N);

    const scalar dlogd((log(dMax)-log(dMin))/(N-1));

    for (label i = 0; i < N; i++)
    {
        this->set
        (
            i,
            new dimensionedScalar
            (
                IOobject::groupName("ds", sectionName(i)),
                dimLength,
                exp(log(dMin) + dlogd*i)
            )
        );
    }
}

// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::particleSizeDistributions::logarithmic::~logarithmic()
{}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //


// ************************************************************************* //
