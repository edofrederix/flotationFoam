#include "particleSizeDistribution.H"
#include "Time.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
    defineTypeNameAndDebug(particleSizeDistribution, 0);
    defineRunTimeSelectionTable(particleSizeDistribution, dictionary);
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::particleSizeDistribution::particleSizeDistribution
(
    const fvMesh& mesh,
    const bool registerObject
)
:
    regIOobject
    (
        IOobject
        (
            typeName,
            mesh.time().time().name(),
            mesh,
            IOobject::NO_READ,
            IOobject::NO_WRITE,
            registerObject
        )
    ),
    PtrList<dimensionedScalar>(0),
    mesh_(mesh)
{}

Foam::particleSizeDistribution::particleSizeDistribution
(
    const dictionary& dict,
    const fvMesh& mesh,
    const bool registerObject
)
:
    regIOobject
    (
        IOobject
        (
            typeName,
            mesh.time().time().name(),
            mesh,
            IOobject::NO_READ,
            IOobject::NO_WRITE,
            registerObject
        )
    ),
    PtrList<dimensionedScalar>(0),
    mesh_(mesh)
{}

// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::particleSizeDistribution::~particleSizeDistribution()
{}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::autoPtr<Foam::particleSizeDistribution> Foam::particleSizeDistribution::New
(
    const dictionary& dict,
    const fvMesh& mesh
)
{
    word particleSizeDistributionType(dict.lookup("type"));

    Info<< "Selecting particle size distribution" << endl;

    dictionaryConstructorTable::iterator cstrIter =
        dictionaryConstructorTablePtr_->find(particleSizeDistributionType);

    if (cstrIter == dictionaryConstructorTablePtr_->end())
    {
        FatalErrorInFunction
            << "Unknown particle size distribution type "
            << particleSizeDistributionType << endl << endl
            << "Valid particle size distribution types are : " << endl
            << dictionaryConstructorTablePtr_->sortedToc()
            << exit(FatalError);
    }

    return cstrIter()(dict, mesh, true);
}

bool Foam::particleSizeDistribution::writeData(Ostream& os) const
{
    return os.good();
}

Foam::word Foam::particleSizeDistribution::sectionName(const label i) const
{
    const label d
    (
        Foam::log10
        (
            scalar(this->size())
        )
      + 1
    );

    const Foam::string sectionName(Foam::name(i));

    return std::string(d - sectionName.length(), '0') + sectionName;
}

// ************************************************************************* //
