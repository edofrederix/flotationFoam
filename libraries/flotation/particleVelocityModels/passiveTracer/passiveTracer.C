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
    const volVectorField& Ul = system_.twoPhasePair().continuous().U();

    forAll(system_.freeParticles(), sectionI)
    {
        surfaceScalarField& phi = system_.freeParticles()[sectionI].phi();
        volVectorField& V = system_.freeParticles()[sectionI].V();

        V = Ul;
        V.correctBoundaryConditions();

        phi = fvc::flux(V);
    }
}

// ************************************************************************* //
