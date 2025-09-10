#include "idealEfficiency.H"
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
    defineTypeNameAndDebug(idealEfficiency, 0);
    addToRunTimeSelectionTable
    (
        dispersedInterceptionEfficiency,
        idealEfficiency,
        dictionary
    );
}
}
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::particleTransferModels::dispersedInterceptionEfficiencies::
idealEfficiency::idealEfficiency
(
    dispersedInterception& transfer,
    const dictionary& dict
)
:
    dispersedInterceptionEfficiency(transfer, dict)
{}

// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::particleTransferModels::dispersedInterceptionEfficiencies::
idealEfficiency::~idealEfficiency()
{}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::particleTransferModels::dispersedInterceptionEfficiencies::
idealEfficiency::E(const volScalarField&) const
{
    return
        tmp<volScalarField>
        (
            new volScalarField
            (
                IOobject
                (
                    "E",
                    transfer_.model().system().mesh().time().time().name(),
                    transfer_.model().system().mesh(),
                    IOobject::NO_READ,
                    IOobject::NO_WRITE
                ),
                transfer_.model().system().mesh(),
                dimensionedScalar(dimless, 1.0)
            )
        );
}

// ************************************************************************* //
