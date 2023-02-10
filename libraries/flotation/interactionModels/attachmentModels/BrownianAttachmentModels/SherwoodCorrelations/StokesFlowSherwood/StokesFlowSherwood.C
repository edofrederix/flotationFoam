#include "StokesFlowSherwood.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace SherwoodCorrelations
{
    defineTypeNameAndDebug(StokesFlowSherwood, 0);
    addToRunTimeSelectionTable(SherwoodCorrelation, StokesFlowSherwood, dictionary);
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::SherwoodCorrelations::StokesFlowSherwood::StokesFlowSherwood
(
    const dictionary& dict,
    const fvMesh& mesh,
    flotationSystem& system
)
:
    SherwoodCorrelation(dict, mesh, system)
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::SherwoodCorrelations::StokesFlowSherwood::~StokesFlowSherwood()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::SherwoodCorrelations::StokesFlowSherwood::Sh
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
            2.0*(0.496*cbrt(Re*Sc) + 0.461)*(1.0+0.0992*cbrt(Re))
        )
    );

    return tSh;
}

// ************************************************************************* //
