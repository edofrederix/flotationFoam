#include "PotentialFlowSherwood.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace SherwoodCorrelations
{
    defineTypeNameAndDebug(PotentialFlowSherwood, 0);
    addToRunTimeSelectionTable(SherwoodCorrelation, PotentialFlowSherwood, dictionary);
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::SherwoodCorrelations::PotentialFlowSherwood::PotentialFlowSherwood
(
    const dictionary& dict,
    const fvMesh& mesh,
    flotationSystem& system
)
:
    SherwoodCorrelation(dict, mesh, system)
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::SherwoodCorrelations::PotentialFlowSherwood::~PotentialFlowSherwood()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::SherwoodCorrelations::PotentialFlowSherwood::Sh
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
                mesh_.time().timeName(),
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
