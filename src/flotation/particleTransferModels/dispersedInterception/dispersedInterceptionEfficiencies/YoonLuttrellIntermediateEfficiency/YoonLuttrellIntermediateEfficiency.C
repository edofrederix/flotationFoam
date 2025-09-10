#include "YoonLuttrellIntermediateEfficiency.H"
#include "dispersedInterception.H"
#include "particleModel.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace particleTransferModels
{
namespace dispersedInterceptionEfficiencies
{
    defineTypeNameAndDebug(YoonLuttrellIntermediateEfficiency, 0);
    addToRunTimeSelectionTable
    (
        dispersedInterceptionEfficiency,
        YoonLuttrellIntermediateEfficiency,
        dictionary
    );
}
}
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::particleTransferModels::dispersedInterceptionEfficiencies::
YoonLuttrellIntermediateEfficiency::YoonLuttrellIntermediateEfficiency
(
    dispersedInterception& transfer,
    const dictionary& dict
)
:
    dispersedInterceptionEfficiency(transfer, dict)
{}

// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::particleTransferModels::dispersedInterceptionEfficiencies::
YoonLuttrellIntermediateEfficiency::~YoonLuttrellIntermediateEfficiency()
{}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::particleTransferModels::dispersedInterceptionEfficiencies::
YoonLuttrellIntermediateEfficiency::E(const volScalarField& N) const
{
    const volScalarField Re(transfer_.interface().Re());
    const volScalarField d(transfer_.interface().dispersed().d());
    const volScalarField U(mag(transfer_.interface().dispersed().U()));

    const_cast<YoonLuttrellIntermediateEfficiency&>(*this).setInductionTime();
    const dimensionedScalar t(induction_->t(N));

    const volScalarField Eatt
    (
        clip
        (
            sqr
            (
                sin
                (
                    2.0*atan
                    (
                        exp
                        (
                          - (45.0 + 8.0*pow(Re,0.72))*U*t
                          / (15.0*d*(1.0/R(N) + 1.0))
                        )
                    )
                )
            )
        )
    );

    const volScalarField Ecol
    (
        clip(sqr(R(N))*(1.5 + 4.0/15.0*pow(Re,0.72)))
    );

    return Eatt*Ecol;
}

// ************************************************************************* //
