#include "inductionTimeModel.H"
#include "fvMesh.H"

// * * * * * * * * * * * * * * * * Selector  * * * * * * * * * * * * * * * * //

Foam::autoPtr<Foam::inductionTimeModel> Foam::inductionTimeModel::New
(
    const dictionary& dict,
    const fvMesh& mesh,
    flotationSystem& system,
    const bool registerObject
)
{
    word inductionTimeModelType(dict.lookup("type"));

    Info<< "Selecting induction time model" << endl;

    dictionaryConstructorTable::iterator cstrIter =
        dictionaryConstructorTablePtr_->find(inductionTimeModelType);

    if (cstrIter == dictionaryConstructorTablePtr_->end())
    {
        FatalErrorInFunction
            << "Unknown inductionTimeModelType type "
            << inductionTimeModelType << endl << endl
            << "Valid inductionTimeModel types are : " << endl
            << dictionaryConstructorTablePtr_->sortedToc()
            << exit(FatalError);
    }

    return cstrIter()(dict, mesh, system, registerObject);
}


// ************************************************************************* //
