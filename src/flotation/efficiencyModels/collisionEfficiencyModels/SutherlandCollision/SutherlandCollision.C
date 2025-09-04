#include "SutherlandCollision.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace collisionEfficiencyModels
{
    defineTypeNameAndDebug(SutherlandCollision, 0);
    addToRunTimeSelectionTable(collisionEfficiencyModel, SutherlandCollision, dictionary);
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::collisionEfficiencyModels::SutherlandCollision::SutherlandCollision
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

Foam::collisionEfficiencyModels::SutherlandCollision::~SutherlandCollision()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::collisionEfficiencyModels::SutherlandCollision::efficiency
(
    const Foam::label& sectionI
) const
{
    tmp<volScalarField> tP(emptyEfficiencyField("Pcol"));

    volScalarField& P = tP.ref();

    P = clip(3.0*R(sectionI));

    return tP;
}

// ************************************************************************* //
