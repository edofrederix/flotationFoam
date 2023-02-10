#include "noDetAttach.H"
#include "flotationSystem.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace deterministicAttachmentModels
{
    defineTypeNameAndDebug(noDetAttach, 0);
    addToRunTimeSelectionTable(deterministicAttachmentModel, noDetAttach, dictionary);
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::deterministicAttachmentModels::noDetAttach::noDetAttach
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

Foam::deterministicAttachmentModels::noDetAttach::~noDetAttach()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::deterministicAttachmentModels::noDetAttach::rate
(
    const Foam::label& sectionI
) const
{
    return emptyRateField("Datt");
}

// ************************************************************************* //
