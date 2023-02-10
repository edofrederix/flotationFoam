#include "deterministicAttachmentModel.H"
#include "fvMesh.H"

// * * * * * * * * * * * * * * * * Selector  * * * * * * * * * * * * * * * * //

Foam::autoPtr<Foam::deterministicAttachmentModel> Foam::deterministicAttachmentModel::New
(
    const dictionary& dict,
    const fvMesh& mesh,
    flotationSystem& system
)
{
    word deterministicAttachmentModelType(dict.lookup("type"));

    Info<< "Selecting deterministic attachment model" << endl;

    dictionaryConstructorTable::iterator cstrIter =
        dictionaryConstructorTablePtr_->find(deterministicAttachmentModelType);

    if (cstrIter == dictionaryConstructorTablePtr_->end())
    {
        FatalErrorInFunction
            << "Unknown deterministicAttachmentModelType type "
            << deterministicAttachmentModelType << endl << endl
            << "Valid deterministicAttachmentModel types are : " << endl
            << dictionaryConstructorTablePtr_->sortedToc()
            << exit(FatalError);
    }

    return cstrIter()(dict, mesh, system, true);
}


// ************************************************************************* //
