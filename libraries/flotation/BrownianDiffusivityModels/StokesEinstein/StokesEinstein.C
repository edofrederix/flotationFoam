#include "StokesEinstein.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"
#include "fundamentalConstants.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace BrownianDiffusivityModels
{
    defineTypeNameAndDebug(StokesEinstein, 0);
    addToRunTimeSelectionTable(BrownianDiffusivityModel, StokesEinstein, dictionary);
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::BrownianDiffusivityModels::StokesEinstein::StokesEinstein
(
    const dictionary& dict,
    const fvMesh& mesh,
    flotationSystem& system,
    const bool registerObject
)
:
    BrownianDiffusivityModel(dict, mesh, system, registerObject),
    f_(dict.lookupOrDefault<scalar>("f", 1.0))
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::BrownianDiffusivityModels::StokesEinstein::~StokesEinstein()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::BrownianDiffusivityModels::StokesEinstein::D
(
    const label& sectionI
) const
{
    tmp<volScalarField> tD
    (
        new volScalarField
        (
            IOobject
            (
                "D",
                mesh_.time().timeName(),
                mesh_,
                IOobject::NO_READ,
                IOobject::NO_WRITE
            ),
            mesh_,
            dimensionedScalar(sqr(dimLength)/dimTime, 0.0)
        )
    );

    volScalarField& D = tD.ref();

    const dimensionedScalar kb(constant::physicoChemical::k);

    const scalar pi(constant::mathematical::pi);

    const volScalarField mul
    (
        system_.twoPhasePair().continuous().thermo().mu()
    );

    const volScalarField T
    (
        system_.twoPhasePair().continuous().thermo().T()
    );

    const dimensionedScalar ds(system_.distribution()[sectionI]);

    D = f_*kb*T/(3.0*pi*mul*ds);

    return tD;
}

// ************************************************************************* //
