#include "continuousEntrainmentRate.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace particleTransferModels
{
    defineTypeNameAndDebug(continuousEntrainmentRate, 0);
    defineRunTimeSelectionTable(continuousEntrainmentRate, dictionary);
}
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::particleTransferModels::continuousEntrainmentRate::continuousEntrainmentRate
(
    continuousEntrainment& transfer,
    const dictionary& dict
)
:
    transfer_(transfer)
{}

// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::particleTransferModels::continuousEntrainmentRate::
~continuousEntrainmentRate()
{}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::autoPtr<Foam::particleTransferModels::continuousEntrainmentRate>
Foam::particleTransferModels::continuousEntrainmentRate::New
(
    continuousEntrainment& transfer,
    const dictionary& dict
)
{
    word modelType(dict.lookup("type"));

    Info<< "Selecting continuous entrainment rate" << endl;

    dictionaryConstructorTable::iterator cstrIter =
        dictionaryConstructorTablePtr_->find(modelType);

    if (cstrIter == dictionaryConstructorTablePtr_->end())
    {
        FatalErrorInFunction
            << "Unknown model type " << modelType << endl << endl
            << "Valid model types are : " << endl
            << dictionaryConstructorTablePtr_->sortedToc()
            << exit(FatalError);
    }

    return cstrIter()(transfer, dict);
}

// ************************************************************************* //
