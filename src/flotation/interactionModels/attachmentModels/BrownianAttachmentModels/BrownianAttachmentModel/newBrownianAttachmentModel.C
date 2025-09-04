#include "BrownianAttachmentModel.H"
#include "fvMesh.H"

// * * * * * * * * * * * * * * * * Selector  * * * * * * * * * * * * * * * * //

Foam::autoPtr<Foam::BrownianAttachmentModel> Foam::BrownianAttachmentModel::New
(
    const dictionary& dict,
    const fvMesh& mesh,
    flotationSystem& system
)
{
    word BrownianAttachmentModelType(dict.lookup("type"));

    Info<< "Selecting Brownian attachment model" << endl;

    dictionaryConstructorTable::iterator cstrIter =
        dictionaryConstructorTablePtr_->find(BrownianAttachmentModelType);

    if (cstrIter == dictionaryConstructorTablePtr_->end())
    {
        FatalErrorInFunction
            << "Unknown BrownianAttachmentModelType type "
            << BrownianAttachmentModelType << endl << endl
            << "Valid BrownianAttachmentModel types are : " << endl
            << dictionaryConstructorTablePtr_->sortedToc()
            << exit(FatalError);
    }

    return cstrIter()(dict, mesh, system, true);
}


// ************************************************************************* //
