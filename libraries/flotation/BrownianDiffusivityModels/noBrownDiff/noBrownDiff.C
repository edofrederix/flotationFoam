#include "noBrownDiff.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"
#include "fundamentalConstants.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace BrownianDiffusivityModels
{
    defineTypeNameAndDebug(noBrownDiff, 0);
    addToRunTimeSelectionTable(BrownianDiffusivityModel, noBrownDiff, dictionary);
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::BrownianDiffusivityModels::noBrownDiff::noBrownDiff
(
    const dictionary& dict,
    const fvMesh& mesh,
    flotationSystem& system,
    const bool registerObject
)
:
    BrownianDiffusivityModel(dict, mesh, system, registerObject)
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::BrownianDiffusivityModels::noBrownDiff::~noBrownDiff()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::BrownianDiffusivityModels::noBrownDiff::D
(
    const label& sectionI
) const
{
    tmp<volScalarField> tD
    (
        new volScalarField
        (
            IOobject
            (
                "D",
                mesh_.time().timeName(),
                mesh_,
                IOobject::NO_READ,
                IOobject::NO_WRITE
            ),
            mesh_,
            dimensionedScalar(sqr(dimLength)/dimTime, 0.0)
        )
    );

    return tD;
}

// ************************************************************************* //
