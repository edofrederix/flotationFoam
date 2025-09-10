#include "passiveTracer.H"
#include "particleModel.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace particleVelocityModels
{
    defineTypeNameAndDebug(passiveTracer, 0);
    addToRunTimeSelectionTable
    (
        particleVelocityModel,
        passiveTracer,
        dictionary
    );
}
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::particleVelocityModels::passiveTracer::passiveTracer
(
    particleModel& model,
    const dictionary& dict
)
:
    particleVelocityModel(model, dict)
{}

// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::particleVelocityModels::passiveTracer::~passiveTracer()
{}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void Foam::particleVelocityModels::passiveTracer::correct()
{
    const surfaceScalarField& phi = model_.phase().phi();

    forAll(model_, i)
    {
        model_[i].phi() = phi;
    }
}

// ************************************************************************* //
