#include "idealCollision.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace collisionEfficiencyModels
{
    defineTypeNameAndDebug(idealCollision, 0);
    addToRunTimeSelectionTable(collisionEfficiencyModel, idealCollision, dictionary);
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::collisionEfficiencyModels::idealCollision::idealCollision
(
    const dictionary& dict,
    const fvMesh& mesh,
    flotationSystem& system,
    const bool registerObject
)
:
    collisionEfficiencyModel(dict, mesh, system, registerObject)
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::collisionEfficiencyModels::idealCollision::~idealCollision()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::collisionEfficiencyModels::idealCollision::efficiency
(
    const Foam::label& sectionI
) const
{
    tmp<volScalarField> tP(emptyEfficiencyField("Pcol"));

    volScalarField& P = tP.ref();

    P = dimensionedScalar(P.name(), P.dimensions(), 1.0);

    return tP;
}

// ************************************************************************* //
