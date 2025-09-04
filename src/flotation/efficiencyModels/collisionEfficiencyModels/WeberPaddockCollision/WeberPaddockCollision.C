#include "WeberPaddockCollision.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace collisionEfficiencyModels
{
    defineTypeNameAndDebug(WeberPaddockCollision, 0);
    addToRunTimeSelectionTable(collisionEfficiencyModel, WeberPaddockCollision, dictionary);
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::collisionEfficiencyModels::WeberPaddockCollision::WeberPaddockCollision
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

Foam::collisionEfficiencyModels::WeberPaddockCollision::~WeberPaddockCollision()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::collisionEfficiencyModels::WeberPaddockCollision::efficiency
(
    const Foam::label& sectionI
) const
{
    tmp<volScalarField> tP(emptyEfficiencyField("Pcol"));

    volScalarField& P = tP.ref();

    tmp<volScalarField> Re(system_.twoPhasePair().Re());

    P = clip
    (
        Foam::sqr(R(sectionI))
      * 3.0/2.0
      * (
            1.0
          + 3.0/16.0*Re/(1.0+0.249*Foam::pow(Re,0.56))
        )
    );

    return tP;
}

// ************************************************************************* //
