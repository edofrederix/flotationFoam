#include "collisionEfficiencyModel.H"
#include "fvMesh.H"

// * * * * * * * * * * * * * * * * Selector  * * * * * * * * * * * * * * * * //

Foam::autoPtr<Foam::collisionEfficiencyModel> Foam::collisionEfficiencyModel::New
(
    const dictionary& dict,
    const fvMesh& mesh,
    flotationSystem& system
)
{
    word collisionEfficiencyModelType(dict.lookup("type"));

    Info<< "Selecting particle collision efficiency model" << endl;

    dictionaryConstructorTable::iterator cstrIter =
        dictionaryConstructorTablePtr_->find(collisionEfficiencyModelType);

    if (cstrIter == dictionaryConstructorTablePtr_->end())
    {
        FatalErrorInFunction
            << "Unknown collisionEfficiencyModelType type "
            << collisionEfficiencyModelType << endl << endl
            << "Valid collisionEfficiencyModel types are : " << endl
            << dictionaryConstructorTablePtr_->sortedToc()
            << exit(FatalError);
    }

    return cstrIter()(dict, mesh, system, true);
}


// ************************************************************************* //
