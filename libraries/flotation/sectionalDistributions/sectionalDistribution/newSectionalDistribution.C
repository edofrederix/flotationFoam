#include "sectionalDistribution.H"
#include "fvMesh.H"

// * * * * * * * * * * * * * * * * Selector  * * * * * * * * * * * * * * * * //

Foam::autoPtr<Foam::sectionalDistribution> Foam::sectionalDistribution::New
(
    const dictionary& dict,
    const fvMesh& mesh
)
{
    word sectionalDistributionType(dict.lookup("type"));

    Info<< "Selecting sectional distribution" << endl;

    dictionaryConstructorTable::iterator cstrIter =
        dictionaryConstructorTablePtr_->find(sectionalDistributionType);

    if (cstrIter == dictionaryConstructorTablePtr_->end())
    {
        FatalErrorInFunction
            << "Unknown sectionalDistributionType type "
            << sectionalDistributionType << endl << endl
            << "Valid sectionalDistribution types are : " << endl
            << dictionaryConstructorTablePtr_->sortedToc()
            << exit(FatalError);
    }

    return cstrIter()(dict, mesh, true);
}


// ************************************************************************* //
