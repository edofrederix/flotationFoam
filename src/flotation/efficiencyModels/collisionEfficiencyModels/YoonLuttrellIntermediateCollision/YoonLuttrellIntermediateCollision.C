#include "YoonLuttrellIntermediateCollision.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace collisionEfficiencyModels
{
    defineTypeNameAndDebug(YoonLuttrellIntermediateCollision, 0);
    addToRunTimeSelectionTable(collisionEfficiencyModel, YoonLuttrellIntermediateCollision, dictionary);
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::collisionEfficiencyModels::YoonLuttrellIntermediateCollision::YoonLuttrellIntermediateCollision
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

Foam::collisionEfficiencyModels::YoonLuttrellIntermediateCollision::~YoonLuttrellIntermediateCollision()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::collisionEfficiencyModels::YoonLuttrellIntermediateCollision::efficiency
(
    const Foam::label& sectionI
) const
{
    tmp<volScalarField> tP(emptyEfficiencyField("Pcol"));

    volScalarField& P = tP.ref();

    tmp<volScalarField> Re(system_.twoPhasePair().Re());

    P = clip(Foam::sqr(R(sectionI))*(1.5+4.0/15.0*Foam::pow(Re,0.72)));

    return tP;
}

// ************************************************************************* //
