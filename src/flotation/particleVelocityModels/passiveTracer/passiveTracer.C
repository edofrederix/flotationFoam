#include "passiveTracer.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"

#include "fvcFlux.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace particleVelocityModels
{
    defineTypeNameAndDebug(passiveTracer, 0);
    addToRunTimeSelectionTable(particleVelocityModel, passiveTracer, dictionary);
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::particleVelocityModels::passiveTracer::passiveTracer
(
    const dictionary& dict,
    const fvMesh& mesh,
    flotationSystem& system,
    const bool registerObject
)
:
    particleVelocityModel(dict, mesh, system, registerObject)
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::particleVelocityModels::passiveTracer::~passiveTracer()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void Foam::particleVelocityModels::passiveTracer::update()
{
    const surfaceScalarField& phi = system_.twoPhasePair().continuous().phi();

    forAll(system_.freeParticles(), sectionI)
    {
        system_.freeParticles()[sectionI].phi() = phi;
    }
}

// ************************************************************************* //
