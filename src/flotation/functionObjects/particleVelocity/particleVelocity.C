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
     && foundObject<flotationSystem>(dictName_)
    )
    {
        systemPtr_ = &lookupObject<flotationSystem>(dictName_);
    }

    if (systemPtr_ != nullptr)
    {
        if
        (
            systemPtr_->interface().phase1().name() != phaseName_
         && systemPtr_->interface().phase2().name() != phaseName_
        )
        {
            FatalErrorInFunction
                << "Phase name " << phaseName_ << " not found for flotation "
                << "system " << systemPtr_->name() << endl
                << abort(FatalError);
        }

        const particleSection& section =
            systemPtr_->interface().phase1().name() == phaseName_
          ? systemPtr_->model1()[sectionNum_]
          : systemPtr_->model2()[sectionNum_];

        store(resultName_, section.V());

        return true;
    }
    else
    {
        cannotFindObject<flotationSystem>(dictName_);

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
    sectionNum_(readLabel(dict.lookup("section"))-1),
    dictName_(dict.lookupOrDefault<word>("dict", "flotationProperties")),
    phaseName_(dict.lookup("phase"))
{
    resultName_ =
        IOobject::groupName("V", phaseName_)
      + ":"
      + Foam::name(sectionNum_+1);
}

// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::functionObjects::particleVelocity::~particleVelocity()
{}

// ************************************************************************* //
