#include "BrownianDiffusivityModel.H"
#include "fvMesh.H"

// * * * * * * * * * * * * * * * * Selector  * * * * * * * * * * * * * * * * //

Foam::autoPtr<Foam::BrownianDiffusivityModel> Foam::BrownianDiffusivityModel::New
(
    const dictionary& dict,
    const fvMesh& mesh,
    flotationSystem& system
)
{
    word BrownianDiffusivityModelType(dict.lookup("type"));

    Info<< "Selecting Brownian diffusivity model" << endl;

    dictionaryConstructorTable::iterator cstrIter =
        dictionaryConstructorTablePtr_->find(BrownianDiffusivityModelType);

    if (cstrIter == dictionaryConstructorTablePtr_->end())
    {
        FatalErrorInFunction
            << "Unknown BrownianDiffusivityModelType type "
            << BrownianDiffusivityModelType << endl << endl
            << "Valid BrownianDiffusivityModel types are : " << endl
            << dictionaryConstructorTablePtr_->sortedToc()
            << exit(FatalError);
    }

    return cstrIter()(dict, mesh, system, true);
}


// ************************************************************************* //
