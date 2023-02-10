#include "BrownianDiffusivityModel.H"
#include "flotationSystem.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
    defineTypeNameAndDebug(BrownianDiffusivityModel, 0);
    defineRunTimeSelectionTable(BrownianDiffusivityModel, dictionary);
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::BrownianDiffusivityModel::BrownianDiffusivityModel
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

Foam::BrownianDiffusivityModel::~BrownianDiffusivityModel()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

bool Foam::BrownianDiffusivityModel::writeData(Ostream& os) const
{
    return os.good();
}

// ************************************************************************* //
