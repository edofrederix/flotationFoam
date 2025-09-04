#include "stochasticAttachmentModel.H"
#include "fvMesh.H"

// * * * * * * * * * * * * * * * * Selector  * * * * * * * * * * * * * * * * //

Foam::autoPtr<Foam::stochasticAttachmentModel> Foam::stochasticAttachmentModel::New
(
    const dictionary& dict,
    const fvMesh& mesh,
    flotationSystem& system
)
{
    word stochasticAttachmentModelType(dict.lookup("type"));

    Info<< "Selecting stochastic attachment model" << endl;

    dictionaryConstructorTable::iterator cstrIter =
        dictionaryConstructorTablePtr_->find(stochasticAttachmentModelType);

    if (cstrIter == dictionaryConstructorTablePtr_->end())
    {
        FatalErrorInFunction
            << "Unknown stochasticAttachmentModelType type "
            << stochasticAttachmentModelType << endl << endl
            << "Valid stochasticAttachmentModel types are : " << endl
            << dictionaryConstructorTablePtr_->sortedToc()
            << exit(FatalError);
    }

    return cstrIter()(dict, mesh, system, true);
}


// ************************************************************************* //
