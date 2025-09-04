#include "particleVelocityModel.H"
#include "fvMesh.H"

// * * * * * * * * * * * * * * * * Selector  * * * * * * * * * * * * * * * * //

Foam::autoPtr<Foam::particleVelocityModel> Foam::particleVelocityModel::New
(
    const dictionary& dict,
    const fvMesh& mesh,
    flotationSystem& system
)
{
    word particleVelocityModelType(dict.lookup("type"));

    Info<< "Selecting particle velocity model" << endl;

    dictionaryConstructorTable::iterator cstrIter =
        dictionaryConstructorTablePtr_->find(particleVelocityModelType);

    if (cstrIter == dictionaryConstructorTablePtr_->end())
    {
        FatalErrorInFunction
            << "Unknown particleVelocityModelType type "
            << particleVelocityModelType << endl << endl
            << "Valid particleVelocityModel types are : " << endl
            << dictionaryConstructorTablePtr_->sortedToc()
            << exit(FatalError);
    }

    return cstrIter()(dict, mesh, system, true);
}


// ************************************************************************* //
