#include "potentialFlowSherwoodNumber.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace SherwoodNumbers
{
    defineTypeNameAndDebug(potentialFlowSherwoodNumber, 0);
    addToRunTimeSelectionTable
    (
        SherwoodNumber,
        potentialFlowSherwoodNumber,
        dictionary
    );
}
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::SherwoodNumbers::potentialFlowSherwoodNumber::potentialFlowSherwoodNumber
(
    const fvMesh& mesh,
    const word type
)
:
    SherwoodNumber(mesh, type)
{}

// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::SherwoodNumbers::potentialFlowSherwoodNumber::
~potentialFlowSherwoodNumber()
{}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::SherwoodNumbers::potentialFlowSherwoodNumber::Sh
(
    const volScalarField& Re,
    const volScalarField& Sc
) const
{
    const scalar pi(constant::mathematical::pi);

    tmp<volScalarField> tSh
    (
        new volScalarField
        (
            IOobject
            (
                "Sh",
                mesh_.time().time().name(),
                mesh_,
                IOobject::NO_READ,
                IOobject::NO_WRITE
            ),
            2.0*sqrt(1.0/(3.0*pi) * (1.0+Re/8.0) * Re*Sc)
        )
    );

    return tSh;
}

// ************************************************************************* //
