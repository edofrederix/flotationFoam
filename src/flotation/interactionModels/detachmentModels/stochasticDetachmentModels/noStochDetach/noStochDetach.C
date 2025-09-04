#include "noStochDetach.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace stochasticDetachmentModels
{
    defineTypeNameAndDebug(noStochDetach, 0);
    addToRunTimeSelectionTable(stochasticDetachmentModel, noStochDetach, dictionary);
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::stochasticDetachmentModels::noStochDetach::noStochDetach
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

Foam::stochasticDetachmentModels::noStochDetach::~noStochDetach()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::stochasticDetachmentModels::noStochDetach::rate
(
    const Foam::label& sectionI
) const
{
    return emptyRateField("Sdet");
}

// ************************************************************************* //
