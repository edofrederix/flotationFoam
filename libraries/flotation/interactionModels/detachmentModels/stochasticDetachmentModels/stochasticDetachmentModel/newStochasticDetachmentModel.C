#include "stochasticDetachmentModel.H"
#include "fvMesh.H"

// * * * * * * * * * * * * * * * * Selector  * * * * * * * * * * * * * * * * //

Foam::autoPtr<Foam::stochasticDetachmentModel> Foam::stochasticDetachmentModel::New
(
    const dictionary& dict,
    const fvMesh& mesh,
    flotationSystem& system
)
{
    word stochasticDetachmentModelType(dict.lookup("type"));

    Info<< "Selecting stochastic detachment model" << endl;

    dictionaryConstructorTable::iterator cstrIter =
        dictionaryConstructorTablePtr_->find(stochasticDetachmentModelType);

    if (cstrIter == dictionaryConstructorTablePtr_->end())
    {
        FatalErrorInFunction
            << "Unknown stochasticDetachmentModelType type "
            << stochasticDetachmentModelType << endl << endl
            << "Valid stochasticDetachmentModel types are : " << endl
            << dictionaryConstructorTablePtr_->sortedToc()
            << exit(FatalError);
    }

    return cstrIter()(dict, mesh, system, true);
}


// ************************************************************************* //
