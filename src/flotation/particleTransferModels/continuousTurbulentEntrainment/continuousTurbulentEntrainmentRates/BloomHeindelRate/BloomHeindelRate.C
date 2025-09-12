#include "BloomHeindelRate.H"
#include "continuousTurbulentEntrainment.H"
#include "particleModel.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace particleTransferModels
{
namespace continuousTurbulentEntrainmentRates
{
    defineTypeNameAndDebug(BloomHeindelRate, 0);
    addToRunTimeSelectionTable
    (
        continuousTurbulentEntrainmentRate,
        BloomHeindelRate,
        dictionary
    );
}
}
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::particleTransferModels::continuousTurbulentEntrainmentRates::BloomHeindelRate::
BloomHeindelRate
(
    continuousTurbulentEntrainment& transfer,
    const dictionary& dict
)
:
    continuousTurbulentEntrainmentRate(transfer, dict)
{}

// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::particleTransferModels::continuousTurbulentEntrainmentRates::BloomHeindelRate::
~BloomHeindelRate()
{}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::particleTransferModels::continuousTurbulentEntrainmentRates::BloomHeindelRate::R
(
    const volScalarField& N
) const
{
    label i = Foam::flotationSystem::sectionNum(N);

    const dimensionedScalar dp(transfer_.model().system().distribution()[i]);
    const volScalarField d(transfer_.interface().dispersed().d());

    const volScalarField& epsilon =
        transfer_.model().otherPhaseTurbulence().epsilon();

    return sqrt(2.0)*cbrt(epsilon)/cbrt(sqr(d + dp));
}

// ************************************************************************* //
