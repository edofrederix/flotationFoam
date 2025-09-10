#include "SaffmanTurnerRate.H"
#include "dispersedTurbulentDeposition.H"
#include "particleModel.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace particleTransferModels
{
namespace dispersedTurbulentDepositionRates
{
    defineTypeNameAndDebug(SaffmanTurnerRate, 0);
    addToRunTimeSelectionTable
    (
        dispersedTurbulentDepositionRate,
        SaffmanTurnerRate,
        dictionary
    );
}
}
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::particleTransferModels::dispersedTurbulentDepositionRates::
SaffmanTurnerRate::SaffmanTurnerRate
(
    dispersedTurbulentDeposition& transfer,
    const dictionary& dict
)
:
    dispersedTurbulentDepositionRate(transfer, dict)
{}

// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::particleTransferModels::dispersedTurbulentDepositionRates::
SaffmanTurnerRate::
~SaffmanTurnerRate()
{}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::particleTransferModels::dispersedTurbulentDepositionRates::
SaffmanTurnerRate::R
(
    const volScalarField& N
) const
{
    label i = Foam::flotationSystem::sectionNum(N);

    const dimensionedScalar dp(transfer_.model().system().distribution()[i]);
    const volScalarField d(transfer_.interface().dispersed().d());

    const volScalarField& epsilon =
        transfer_.model().turbulence().epsilon();

    const volScalarField& nu =
        transfer_.interface().continuous().fluidThermo().nu();

    return 0.1625*pow3(d + dp)*sqrt(epsilon/nu);
}

// ************************************************************************* //
