#include "YoonLuttrellStokesEfficiency.H"
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
    defineTypeNameAndDebug(YoonLuttrellStokesEfficiency, 0);
    addToRunTimeSelectionTable
    (
        dispersedInterceptionEfficiency,
        YoonLuttrellStokesEfficiency,
        dictionary
    );
}
}
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::particleTransferModels::dispersedInterceptionEfficiencies::
YoonLuttrellStokesEfficiency::YoonLuttrellStokesEfficiency
(
    dispersedInterception& transfer,
    const dictionary& dict
)
:
    dispersedInterceptionEfficiency(transfer, dict)
{}

// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::particleTransferModels::dispersedInterceptionEfficiencies::
YoonLuttrellStokesEfficiency::~YoonLuttrellStokesEfficiency()
{}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::particleTransferModels::dispersedInterceptionEfficiencies::
YoonLuttrellStokesEfficiency::E(const volScalarField& N) const
{
    const volScalarField d(transfer_.interface().dispersed().d());
    const volScalarField U(mag(transfer_.interface().dispersed().U()));

    const_cast<YoonLuttrellStokesEfficiency&>(*this).setInductionTime();
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
                          - 3.0*U*t/(d*(1.0/R(N) + 1.0))
                        )
                    )
                )
            )
        )
    );

    const volScalarField Ecol(clip(1.5*sqr(R(N))));

    return Eatt*Ecol;
}

// ************************************************************************* //
