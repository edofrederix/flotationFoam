#include "BloomHeindelRate.H"
#include "continuousEntrainment.H"
#include "particleModel.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace particleTransferModels
{
namespace continuousEntrainmentRates
{
    defineTypeNameAndDebug(BloomHeindelRate, 0);
    addToRunTimeSelectionTable
    (
        continuousEntrainmentRate,
        BloomHeindelRate,
        dictionary
    );
}
}
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::particleTransferModels::continuousEntrainmentRates::BloomHeindelRate::
BloomHeindelRate
(
    continuousEntrainment& transfer,
    const dictionary& dict
)
:
    continuousEntrainmentRate(transfer, dict)
{}

// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::particleTransferModels::continuousEntrainmentRates::BloomHeindelRate::
~BloomHeindelRate()
{}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::particleTransferModels::continuousEntrainmentRates::BloomHeindelRate::R
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
