#include "attachmentEfficiencyModel.H"
#include "fvMesh.H"

// * * * * * * * * * * * * * * * * Selector  * * * * * * * * * * * * * * * * //

Foam::autoPtr<Foam::attachmentEfficiencyModel> Foam::attachmentEfficiencyModel::New
(
    const dictionary& dict,
    const fvMesh& mesh,
    flotationSystem& system
)
{
    word attachmentEfficiencyModelType(dict.lookup("type"));

    Info<< "Selecting particle attachment efficiency model" << endl;

    dictionaryConstructorTable::iterator cstrIter =
        dictionaryConstructorTablePtr_->find(attachmentEfficiencyModelType);

    if (cstrIter == dictionaryConstructorTablePtr_->end())
    {
        FatalErrorInFunction
            << "Unknown attachmentEfficiencyModelType type "
            << attachmentEfficiencyModelType << endl << endl
            << "Valid attachmentEfficiencyModel types are : " << endl
            << dictionaryConstructorTablePtr_->sortedToc()
            << exit(FatalError);
    }

    return cstrIter()(dict, mesh, system, true);
}


// ************************************************************************* //
