#include "YoonLuttrellStokesCollision.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace collisionEfficiencyModels
{
    defineTypeNameAndDebug(YoonLuttrellStokesCollision, 0);
    addToRunTimeSelectionTable(collisionEfficiencyModel, YoonLuttrellStokesCollision, dictionary);
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::collisionEfficiencyModels::YoonLuttrellStokesCollision::YoonLuttrellStokesCollision
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

Foam::collisionEfficiencyModels::YoonLuttrellStokesCollision::~YoonLuttrellStokesCollision()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::collisionEfficiencyModels::YoonLuttrellStokesCollision::efficiency
(
    const Foam::label& sectionI
) const
{
    tmp<volScalarField> tP(emptyEfficiencyField("Pcol"));

    volScalarField& P = tP.ref();

    P = clip(Foam::sqr(R(sectionI))*1.5);

    return tP;
}

// ************************************************************************* //
