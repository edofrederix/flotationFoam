#include "noStochAttach.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace stochasticAttachmentModels
{
    defineTypeNameAndDebug(noStochAttach, 0);
    addToRunTimeSelectionTable(stochasticAttachmentModel, noStochAttach, dictionary);
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::stochasticAttachmentModels::noStochAttach::noStochAttach
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

Foam::stochasticAttachmentModels::noStochAttach::~noStochAttach()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::stochasticAttachmentModels::noStochAttach::rate
(
    const Foam::label& sectionI
) const
{
    return emptyRateField("Satt");
}

// ************************************************************************* //
