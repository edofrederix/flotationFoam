#include "inductionTime.H"
#include "dispersedInterception.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace particleTransferModels
{
    defineTypeNameAndDebug(inductionTime, 0);
    defineRunTimeSelectionTable(inductionTime, dictionary);
}
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::particleTransferModels::inductionTime::inductionTime
(
    dispersedInterception& transfer,
    const dictionary& dict
)
:
    transfer_(transfer)
{}

// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::particleTransferModels::inductionTime::~inductionTime()
{}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::autoPtr<Foam::particleTransferModels::inductionTime>
Foam::particleTransferModels::inductionTime::New
(
    dispersedInterception& transfer,
    const dictionary& dict
)
{
    word inductionTimeType(dict.lookup("type"));

    Info<< "Selecting induction time " << endl;

    dictionaryConstructorTable::iterator cstrIter =
        dictionaryConstructorTablePtr_->find(inductionTimeType);

    if (cstrIter == dictionaryConstructorTablePtr_->end())
    {
        FatalErrorInFunction
            << "Unknown induction time " << inductionTimeType << endl << endl
            << "Valid induction times are : " << endl
            << dictionaryConstructorTablePtr_->sortedToc()
            << exit(FatalError);
    }

    return cstrIter()(transfer, dict);
}

// ************************************************************************* //
