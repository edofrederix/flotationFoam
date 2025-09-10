#include "dispersedTurbulentDepositionRate.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace particleTransferModels
{
    defineTypeNameAndDebug(dispersedTurbulentDepositionRate, 0);
    defineRunTimeSelectionTable(dispersedTurbulentDepositionRate, dictionary);
}
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::particleTransferModels::dispersedTurbulentDepositionRate::
dispersedTurbulentDepositionRate
(
    dispersedTurbulentDeposition& transfer,
    const dictionary& dict
)
:
    transfer_(transfer)
{}

// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::particleTransferModels::dispersedTurbulentDepositionRate::
~dispersedTurbulentDepositionRate()
{}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::autoPtr<Foam::particleTransferModels::dispersedTurbulentDepositionRate>
Foam::particleTransferModels::dispersedTurbulentDepositionRate::New
(
    dispersedTurbulentDeposition& transfer,
    const dictionary& dict
)
{
    word modelType(dict.lookup("type"));

    Info<< "Selecting dispersed turbulent deposition rate" << endl;

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
