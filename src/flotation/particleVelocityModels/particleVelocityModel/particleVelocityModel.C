#include "particleVelocityModel.H"
#include "particleModel.H"
#include "flotationSystem.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
    defineTypeNameAndDebug(particleVelocityModel, 0);
    defineRunTimeSelectionTable(particleVelocityModel, dictionary);
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::particleVelocityModel::particleVelocityModel
(
    particleModel& model,
    const dictionary& dict
)
:
    regIOobject
    (
        IOobject
        (
            typeName,
            model.system().mesh().time().time().name(),
            model.system().mesh(),
            IOobject::NO_READ,
            IOobject::NO_WRITE
        )
    ),
    model_(model),
    dict_(dict)
{}

// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::particleVelocityModel::~particleVelocityModel()
{}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::autoPtr<Foam::particleVelocityModel> Foam::particleVelocityModel::New
(
    particleModel& model,
    const dictionary& dict
)
{
    word particleVelocityModelType(dict.lookup("type"));

    Info<< "Selecting particle velocity model" << endl;

    dictionaryConstructorTable::iterator cstrIter =
        dictionaryConstructorTablePtr_->find(particleVelocityModelType);

    if (cstrIter == dictionaryConstructorTablePtr_->end())
    {
        FatalErrorInFunction
            << "Unknown particle velocity model "
            << particleVelocityModelType << endl << endl
            << "Valid particle velocity models are : " << endl
            << dictionaryConstructorTablePtr_->sortedToc()
            << exit(FatalError);
    }

    return cstrIter()(model, dict);
}

bool Foam::particleVelocityModel::writeData(Ostream& os) const
{
    return os.good();
}

// ************************************************************************* //
