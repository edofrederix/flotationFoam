#include "SherwoodCorrelation.H"
#include "fvMesh.H"

// * * * * * * * * * * * * * * * * Selector  * * * * * * * * * * * * * * * * //

Foam::autoPtr<Foam::SherwoodCorrelation> Foam::SherwoodCorrelation::New
(
    const dictionary& dict,
    const fvMesh& mesh,
    flotationSystem& system
)
{
    word SherwoodCorrelationType(dict.lookup("type"));

    Info<< "Selecting Sherwood correlation" << endl;

    dictionaryConstructorTable::iterator cstrIter =
        dictionaryConstructorTablePtr_->find(SherwoodCorrelationType);

    if (cstrIter == dictionaryConstructorTablePtr_->end())
    {
        FatalErrorInFunction
            << "Unknown SherwoodCorrelationType type "
            << SherwoodCorrelationType << endl << endl
            << "Valid SherwoodCorrelation types are : " << endl
            << dictionaryConstructorTablePtr_->sortedToc()
            << exit(FatalError);
    }

    return cstrIter()(dict, mesh, system);
}


// ************************************************************************* //
