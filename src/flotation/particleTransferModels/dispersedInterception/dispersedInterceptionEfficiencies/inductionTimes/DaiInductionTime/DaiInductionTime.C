#include "DaiInductionTime.H"
#include "dispersedInterception.H"
#include "particleModel.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace particleTransferModels
{
namespace inductionTimes
{
    defineTypeNameAndDebug(DaiInductionTime, 0);
    addToRunTimeSelectionTable(inductionTime, DaiInductionTime, dictionary);
}
}
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::particleTransferModels::inductionTimes::DaiInductionTime::DaiInductionTime
(
    dispersedInterception& transfer,
    const dictionary& dict
)
:
    inductionTime(transfer, dict),
    A_(readScalar(dict.lookup("A"))),
    B_(readScalar(dict.lookup("B")))
{}

// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::particleTransferModels::inductionTimes::DaiInductionTime::
~DaiInductionTime()
{}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::dimensionedScalar
Foam::particleTransferModels::inductionTimes::DaiInductionTime::t
(
    const volScalarField& N
) const
{
    label i = Foam::flotationSystem::sectionNum(N);

    const scalar dp =
        transfer_.model().system().distribution()[i].value();

    return dimensionedScalar(dimTime, A_*pow(dp, B_));
}

// ************************************************************************* //
