#include "interactionModel.H"
#include "flotationSystem.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
    defineTypeNameAndDebug(interactionModel, 0);
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::interactionModel::interactionModel
(
    const dictionary& dict,
    const fvMesh& mesh,
    flotationSystem& system,
    const bool registerObject,
    const word subTypeName,
    const word subSubTypeName
)
:
    regIOobject
    (
        IOobject
        (
            IOobject::groupName
            (
                IOobject::groupName(typeName, subTypeName), subSubTypeName
            ),
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

Foam::interactionModel::~interactionModel()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

bool Foam::interactionModel::writeData(Ostream& os) const
{
    return os.good();
}


// ************************************************************************* //
