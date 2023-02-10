#include "noBrownAttach.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace BrownianAttachmentModels
{
    defineTypeNameAndDebug(noBrownAttach, 0);
    addToRunTimeSelectionTable(BrownianAttachmentModel, noBrownAttach, dictionary);
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::BrownianAttachmentModels::noBrownAttach::noBrownAttach
(
    const dictionary& dict,
    const fvMesh& mesh,
    flotationSystem& system,
    const bool registerObject
)
:
    BrownianAttachmentModel(dict, mesh, system, registerObject)
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::BrownianAttachmentModels::noBrownAttach::~noBrownAttach()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::BrownianAttachmentModels::noBrownAttach::rate
(
    const Foam::label& sectionI
) const
{
    return emptyRateField("Batt");
}

// ************************************************************************* //
