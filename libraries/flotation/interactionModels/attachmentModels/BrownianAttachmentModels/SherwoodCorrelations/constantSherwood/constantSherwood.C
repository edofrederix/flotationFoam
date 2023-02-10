#include "constantSherwood.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace SherwoodCorrelations
{
    defineTypeNameAndDebug(constantSherwood, 0);
    addToRunTimeSelectionTable(SherwoodCorrelation, constantSherwood, dictionary);
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::SherwoodCorrelations::constantSherwood::constantSherwood
(
    const dictionary& dict,
    const fvMesh& mesh,
    flotationSystem& system
)
:
    SherwoodCorrelation(dict, mesh, system),
    Sh_(readScalar(dict.lookup("Sh")))
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::SherwoodCorrelations::constantSherwood::~constantSherwood()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::SherwoodCorrelations::constantSherwood::Sh
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
                mesh_.time().timeName(),
                mesh_,
                IOobject::NO_READ,
                IOobject::NO_WRITE
            ),
            mesh_,
            dimensionedScalar(dimless, Sh_)
        )
    );

    return tSh;
}

// ************************************************************************* //
