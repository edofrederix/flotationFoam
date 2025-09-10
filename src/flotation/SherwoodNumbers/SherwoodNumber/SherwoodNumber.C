#include "SherwoodNumber.H"
#include "flotationSystem.H"
#include "constantSherwoodNumber.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
    defineTypeNameAndDebug(SherwoodNumber, 0);
    defineRunTimeSelectionTable(SherwoodNumber, dictionary);
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::SherwoodNumber::SherwoodNumber
(
    const fvMesh& mesh,
    const word type
)
:
    mesh_(mesh)
{}

// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::SherwoodNumber::~SherwoodNumber()
{}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::autoPtr<Foam::SherwoodNumber> Foam::SherwoodNumber::New
(
    const fvMesh& mesh,
    const word type
)
{
    Info<< "Selecting Sherwood number" << endl;

    dictionaryConstructorTable::iterator cstrIter =
        dictionaryConstructorTablePtr_->find(type);

    if (cstrIter == dictionaryConstructorTablePtr_->end())
    {
        return
            autoPtr<SherwoodNumber>
            (
                new SherwoodNumbers::constantSherwoodNumber
                (
                    mesh,
                    atof(type.c_str())
                )
            );
    }

    return cstrIter()(mesh, type);
}

// ************************************************************************* //
