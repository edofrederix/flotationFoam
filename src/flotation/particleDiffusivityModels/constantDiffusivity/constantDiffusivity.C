#include "constantDiffusivity.H"
#include "particleModel.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"
#include "fundamentalConstants.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace particleDiffusivityModels
{
    defineTypeNameAndDebug(constantDiffusivity, 0);
    addToRunTimeSelectionTable
    (
        particleDiffusivityModel,
        constantDiffusivity,
        dictionary
    );
}
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::particleDiffusivityModels::constantDiffusivity::constantDiffusivity
(
    particleModel& model,
    const dictionary& dict
)
:
    particleDiffusivityModel(model, dict),
    D_(dimArea/dimTime, readScalar(dict.lookup("D")))
{}

// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::particleDiffusivityModels::constantDiffusivity::~constantDiffusivity()
{}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void Foam::particleDiffusivityModels::constantDiffusivity::correct()
{
    forAll(model_, i)
    {
        model_[i].D() = D_;
    }
}

// ************************************************************************* //
