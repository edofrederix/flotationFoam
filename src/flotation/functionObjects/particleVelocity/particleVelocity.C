#include "particleVelocity.H"
#include "addToRunTimeSelectionTable.H"
#include "flotationSystem.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace functionObjects
{
    defineTypeNameAndDebug(particleVelocity, 0);

    addToRunTimeSelectionTable
    (
        functionObject,
        particleVelocity,
        dictionary
    );
}
}


// * * * * * * * * * * * * * Private Member Functions  * * * * * * * * * * * //

bool Foam::functionObjects::particleVelocity::calc()
{
    if
    (
        systemPtr_ == nullptr
     && foundObject<flotationSystem>("flotationProperties")
    )
    {
        systemPtr_ = &lookupObject<flotationSystem>("flotationProperties");
    }

    if (systemPtr_ != nullptr)
    {
        store
        (
            resultName_,
            systemPtr_->freeParticles()[sectionNum_].V()
        );

        return true;
    }
    else
    {
        cannotFindObject<flotationSystem>("flotationProperties");

        return false;
    }
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::functionObjects::particleVelocity::particleVelocity
(
    const word& name,
    const Time& runTime,
    const dictionary& dict
)
:
    fieldExpression(name, runTime, dict, "V"),
    systemPtr_(nullptr),
    sectionNum_(readLabel(dict.lookup("section")))
{
    resultName_ = IOobject::groupName("V", Foam::name(sectionNum_));
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::functionObjects::particleVelocity::~particleVelocity()
{}

// ************************************************************************* //
