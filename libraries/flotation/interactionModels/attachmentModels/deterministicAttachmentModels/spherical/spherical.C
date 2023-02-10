#include "spherical.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace deterministicAttachmentModels
{
    defineTypeNameAndDebug(spherical, 0);
    addToRunTimeSelectionTable(deterministicAttachmentModel, spherical, dictionary);
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::deterministicAttachmentModels::spherical::spherical
(
    const dictionary& dict,
    const fvMesh& mesh,
    flotationSystem& system,
    const bool registerObject
)
:
    deterministicAttachmentModel(dict, mesh, system, registerObject)
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::deterministicAttachmentModels::spherical::~spherical()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::deterministicAttachmentModels::spherical::rate
(
    const Foam::label& sectionI
) const
{
    tmp<volScalarField> tD(emptyRateField("Datt"));

    volScalarField& D = tD.ref();

    const dimensionedScalar ds(system_.distribution()[sectionI]);

    const scalar pi(constant::mathematical::pi);

    tmp<volScalarField> db(system_.twoPhasePair().dispersed().d());

    const volVectorField& U = system_.twoPhasePair().dispersed().U();
    const volVectorField& V = system_.freeParticles()[sectionI].V();

    D = 0.25 * pi * sqr(db + ds) * mag(U-V);

    return tD;
}

// ************************************************************************* //
