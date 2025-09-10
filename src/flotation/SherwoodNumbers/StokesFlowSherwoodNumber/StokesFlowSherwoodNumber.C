#include "StokesFlowSherwoodNumber.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace SherwoodNumbers
{
    defineTypeNameAndDebug(StokesFlowSherwoodNumber, 0);
    addToRunTimeSelectionTable
    (
        SherwoodNumber,
        StokesFlowSherwoodNumber,
        dictionary
    );
}
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::SherwoodNumbers::StokesFlowSherwoodNumber::StokesFlowSherwoodNumber
(
    const fvMesh& mesh,
    const word type
)
:
    SherwoodNumber(mesh, type)
{}

// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::SherwoodNumbers::StokesFlowSherwoodNumber::~StokesFlowSherwoodNumber()
{}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::SherwoodNumbers::StokesFlowSherwoodNumber::Sh
(
    const volScalarField& Re,
    const volScalarField& Sc
) const
{
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
            2.0*(0.496*cbrt(Re*Sc) + 0.461)*(1.0+0.0992*cbrt(Re))
        )
    );

    return tSh;
}

// ************************************************************************* //
