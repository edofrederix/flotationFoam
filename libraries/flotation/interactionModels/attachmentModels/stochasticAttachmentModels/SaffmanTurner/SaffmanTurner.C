#include "SaffmanTurner.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace stochasticAttachmentModels
{
    defineTypeNameAndDebug(SaffmanTurner, 0);
    addToRunTimeSelectionTable(stochasticAttachmentModel, SaffmanTurner, dictionary);
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::stochasticAttachmentModels::SaffmanTurner::SaffmanTurner
(
    const dictionary& dict,
    const fvMesh& mesh,
    flotationSystem& system,
    const bool registerObject
)
:
    stochasticAttachmentModel(dict, mesh, system, registerObject)
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::stochasticAttachmentModels::SaffmanTurner::~SaffmanTurner()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::stochasticAttachmentModels::SaffmanTurner::rate
(
    const Foam::label& sectionI
) const
{
    tmp<volScalarField> tS(emptyRateField("Satt"));

    volScalarField& S = tS.ref();

    const dimensionedScalar ds(system_.distribution()[sectionI]);

    tmp<volScalarField> db(system_.twoPhasePair().dispersed().d());

    const volScalarField& epsilon =
        system_.continuousTurbulence().epsilon();

    const volScalarField& nu =
        system_.twoPhasePair().continuous().thermo().nu();

    S = 0.1625 * Foam::pow(db+ds, 3.0) * sqrt(epsilon/nu);

    return tS;
}

// ************************************************************************* //
