#include "constantSherwoodNumber.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace SherwoodNumbers
{
    defineTypeNameAndDebug(constantSherwoodNumber, 0);
    addToRunTimeSelectionTable
    (
        SherwoodNumber,
        constantSherwoodNumber,
        dictionary
    );
}
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::SherwoodNumbers::constantSherwoodNumber::constantSherwoodNumber
(
    const fvMesh& mesh,
    const word type
)
:
    SherwoodNumber(mesh, type),
    Sh_(atof(type.c_str()))
{}

Foam::SherwoodNumbers::constantSherwoodNumber::constantSherwoodNumber
(
    const fvMesh& mesh,
    const scalar value
)
:
    SherwoodNumber(mesh, "constant"),
    Sh_(value)
{}

// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::SherwoodNumbers::constantSherwoodNumber::~constantSherwoodNumber()
{}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::SherwoodNumbers::constantSherwoodNumber::Sh
(
    const volScalarField& Re,
    const volScalarField& Sc
) const
{
    return
        tmp<volScalarField>
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
                mesh_,
                dimensionedScalar(dimless, Sh_)
            )
        );
}

// ************************************************************************* //
