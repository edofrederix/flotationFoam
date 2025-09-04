#include "BloomHeindel.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace stochasticDetachmentModels
{
    defineTypeNameAndDebug(BloomHeindel, 0);
    addToRunTimeSelectionTable(stochasticDetachmentModel, BloomHeindel, dictionary);
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::stochasticDetachmentModels::BloomHeindel::BloomHeindel
(
    const dictionary& dict,
    const fvMesh& mesh,
    flotationSystem& system,
    const bool registerObject
)
:
    stochasticDetachmentModel(dict, mesh, system, registerObject)
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::stochasticDetachmentModels::BloomHeindel::~BloomHeindel()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::stochasticDetachmentModels::BloomHeindel::rate
(
    const Foam::label& sectionI
) const
{
    tmp<volScalarField> tS(emptyRateField("Sdet"));

    volScalarField& S = tS.ref();

    const dimensionedScalar ds(system_.distribution()[sectionI]);

    tmp<volScalarField> db(system_.twoPhasePair().dispersed().d());

    const volScalarField& epsilon =
        system_.continuousTurbulence().epsilon();

    S = Foam::sqrt(2.0) * Foam::pow(db+ds, -2.0/3.0) * Foam::pow(epsilon, 1.0/3.0);

    return tS;
}

// ************************************************************************* //
