#include "RanzMarshallSherwood.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace SherwoodCorrelations
{
    defineTypeNameAndDebug(RanzMarshallSherwood, 0);
    addToRunTimeSelectionTable(SherwoodCorrelation, RanzMarshallSherwood, dictionary);
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::SherwoodCorrelations::RanzMarshallSherwood::RanzMarshallSherwood
(
    const dictionary& dict,
    const fvMesh& mesh,
    flotationSystem& system
)
:
    SherwoodCorrelation(dict, mesh, system)
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::SherwoodCorrelations::RanzMarshallSherwood::~RanzMarshallSherwood()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::SherwoodCorrelations::RanzMarshallSherwood::Sh
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
            2.0 + 0.6*sqrt(Re)*cbrt(Sc)
        )
    );

    return tSh;
}

// ************************************************************************* //
