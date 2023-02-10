#include "idealStabilization.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace stabilizationEfficiencyModels
{
    defineTypeNameAndDebug(idealStabilization, 0);
    addToRunTimeSelectionTable(stabilizationEfficiencyModel, idealStabilization, dictionary);
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::stabilizationEfficiencyModels::idealStabilization::idealStabilization
(
    const dictionary& dict,
    const fvMesh& mesh,
    flotationSystem& system,
    const bool registerObject
)
:
    stabilizationEfficiencyModel(dict, mesh, system, registerObject)
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::stabilizationEfficiencyModels::idealStabilization::~idealStabilization()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::stabilizationEfficiencyModels::idealStabilization::efficiency
(
    const Foam::label& sectionI
) const
{
    tmp<volScalarField> tP(emptyEfficiencyField("Pstab"));

    volScalarField& P = tP.ref();

    P = dimensionedScalar(P.name(), P.dimensions(), 1.0);

    return tP;
}

// ************************************************************************* //
