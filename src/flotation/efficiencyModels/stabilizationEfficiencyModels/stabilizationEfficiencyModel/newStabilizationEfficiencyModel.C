#include "stabilizationEfficiencyModel.H"
#include "fvMesh.H"

// * * * * * * * * * * * * * * * * Selector  * * * * * * * * * * * * * * * * //

Foam::autoPtr<Foam::stabilizationEfficiencyModel> Foam::stabilizationEfficiencyModel::New
(
    const dictionary& dict,
    const fvMesh& mesh,
    flotationSystem& system
)
{
    word stabilizationEfficiencyModelType(dict.lookup("type"));

    Info<< "Selecting particle stabilization efficiency model" << endl;

    dictionaryConstructorTable::iterator cstrIter =
        dictionaryConstructorTablePtr_->find(stabilizationEfficiencyModelType);

    if (cstrIter == dictionaryConstructorTablePtr_->end())
    {
        FatalErrorInFunction
            << "Unknown stabilizationEfficiencyModelType type "
            << stabilizationEfficiencyModelType << endl << endl
            << "Valid stabilizationEfficiencyModel types are : " << endl
            << dictionaryConstructorTablePtr_->sortedToc()
            << exit(FatalError);
    }

    return cstrIter()(dict, mesh, system, true);
}


// ************************************************************************* //
