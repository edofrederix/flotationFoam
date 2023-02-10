#include "sectionalDistribution.H"
#include "Time.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
    defineTypeNameAndDebug(sectionalDistribution, 0);
    defineRunTimeSelectionTable(sectionalDistribution, dictionary);
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::sectionalDistribution::sectionalDistribution
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
            mesh.time().timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::NO_WRITE,
            registerObject
        )
    ),
    PtrList<dimensionedScalar>(0),
    mesh_(mesh)
{}


Foam::sectionalDistribution::sectionalDistribution
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
            mesh.time().timeName(),
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

Foam::sectionalDistribution::~sectionalDistribution()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

bool Foam::sectionalDistribution::writeData(Ostream& os) const
{
    return os.good();
}

Foam::word Foam::sectionalDistribution::sectionName(const label sectionI) const
{
    const label d
    (
        Foam::log10
        (
            scalar(this->size())
        )
      + 1
    );

    const Foam::string sectionName(Foam::name(sectionI));

    return std::string(d-sectionName.length(), '0') + sectionName;
}

// ************************************************************************* //
