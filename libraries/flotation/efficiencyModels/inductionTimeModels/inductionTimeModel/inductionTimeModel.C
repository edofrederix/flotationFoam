#include "inductionTimeModel.H"
#include "flotationSystem.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
    defineTypeNameAndDebug(inductionTimeModel, 0);
    defineRunTimeSelectionTable(inductionTimeModel, dictionary);
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::inductionTimeModel::inductionTimeModel
(
    const dictionary& dict,
    const fvMesh& mesh,
    flotationSystem& system,
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
    mesh_(mesh),
    system_(system),
    dict_(dict)
{}

// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::inductionTimeModel::~inductionTimeModel()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

bool Foam::inductionTimeModel::writeData(Ostream& os) const
{
    return os.good();
}

// ************************************************************************* //
