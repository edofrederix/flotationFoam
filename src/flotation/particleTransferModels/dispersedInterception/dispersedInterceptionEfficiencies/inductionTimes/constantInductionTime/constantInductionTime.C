#include "constantInductionTime.H"
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
    defineTypeNameAndDebug(constantInductionTime, 0);
    addToRunTimeSelectionTable
    (
        inductionTime,
        constantInductionTime,
        dictionary
    );
}
}
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::particleTransferModels::inductionTimes::constantInductionTime::
constantInductionTime
(
    dispersedInterception& transfer,
    const dictionary& dict
)
:
    inductionTime(transfer, dict),
    t_(readScalar(dict.lookup("t")))
{}

// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::particleTransferModels::inductionTimes::constantInductionTime::
~constantInductionTime()
{}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::dimensionedScalar
Foam::particleTransferModels::inductionTimes::constantInductionTime::t
(
    const volScalarField&
) const
{
    return dimensionedScalar(dimTime, t_);
}

// ************************************************************************* //
