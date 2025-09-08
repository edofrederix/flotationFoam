#include "flotation.H"
#include "fvModels.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace fv
{
    defineTypeNameAndDebug(flotation, 0);
    addToRunTimeSelectionTable
    (
        fvModel,
        flotation,
        dictionary
    );
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::fv::flotation::flotation
(
    const word& name,
    const word& modelType,
    const fvMesh& mesh,
    const dictionary& dict
)
:
    fvModel(name, modelType, mesh, dict)
{
    const phaseSystem& fluid =
        mesh.lookupObject<phaseSystem>("phaseProperties");

    if (dict.found("dict"))
    {
        system_.reset
        (
            new flotationSystem(fluid, mesh, word(dict.lookup("dict")))
        );
    }
    else
    {
        system_.reset
        (
            new flotationSystem(fluid, mesh)
        );
    }
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::fv::flotation::~flotation()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void Foam::fv::flotation::correct()
{
    if (mesh().time().timeIndex() > 1)
    {
        system_->solve();
    }
}

bool Foam::fv::flotation::movePoints()
{
    return true;
}

void Foam::fv::flotation::topoChange(const polyTopoChangeMap& map)
{}

void Foam::fv::flotation::mapMesh(const polyMeshMap& map)
{}

void Foam::fv::flotation::distribute(const polyDistributionMap& map)
{}

bool Foam::fv::flotation::read(const dictionary& dict)
{
    if (fvModel::read(dict))
    {
        return true;
    }
    else
    {
        return false;
    }
}


// ************************************************************************* //
