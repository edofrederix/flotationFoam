#include "RanzMarshallSherwoodNumber.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace SherwoodNumbers
{
    defineTypeNameAndDebug(RanzMarshallSherwoodNumber, 0);
    addToRunTimeSelectionTable(SherwoodNumber, RanzMarshallSherwoodNumber, dictionary);
}
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::SherwoodNumbers::RanzMarshallSherwoodNumber::RanzMarshallSherwoodNumber
(
    const fvMesh& mesh,
    const word type
)
:
    SherwoodNumber(mesh, type)
{}

// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::SherwoodNumbers::RanzMarshallSherwoodNumber::~RanzMarshallSherwoodNumber()
{}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::SherwoodNumbers::RanzMarshallSherwoodNumber::Sh
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
            2.0 + 0.6*sqrt(Re)*cbrt(Sc)
        )
    );

    return tSh;
}

// ************************************************************************* //
