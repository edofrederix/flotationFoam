#include "SutherlandEfficiency.H"
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
    defineTypeNameAndDebug(SutherlandEfficiency, 0);
    addToRunTimeSelectionTable
    (
        dispersedInterceptionEfficiency,
        SutherlandEfficiency,
        dictionary
    );
}
}
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::particleTransferModels::dispersedInterceptionEfficiencies::
SutherlandEfficiency::SutherlandEfficiency
(
    dispersedInterception& transfer,
    const dictionary& dict
)
:
    dispersedInterceptionEfficiency(transfer, dict)
{}

// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::particleTransferModels::dispersedInterceptionEfficiencies::
SutherlandEfficiency::~SutherlandEfficiency()
{}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::particleTransferModels::dispersedInterceptionEfficiencies::
SutherlandEfficiency::E(const volScalarField& N) const
{
    label i = Foam::flotationSystem::sectionNum(N);

    const volScalarField d(transfer_.interface().dispersed().d());
    const volScalarField U(mag(transfer_.interface().dispersed().U()));

    const_cast<SutherlandEfficiency&>(*this).setInductionTime();
    const dimensionedScalar t(induction_->t(N));
    const dimensionedScalar dp(transfer_.model().system().distribution()[i]);

    const volScalarField Eatt(clip(sqr(sin(exp(-1.5*U*t/(d+dp))))));
    const volScalarField Ecol(clip(3.0*R(N)));

    return Eatt*Ecol;
}

// ************************************************************************* //
