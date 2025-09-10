#include "particleDiffusivityModel.H"
#include "particleModel.H"
#include "flotationSystem.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
    defineTypeNameAndDebug(particleDiffusivityModel, 0);
    defineRunTimeSelectionTable(particleDiffusivityModel, dictionary);
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::particleDiffusivityModel::particleDiffusivityModel
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

Foam::particleDiffusivityModel::~particleDiffusivityModel()
{}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::autoPtr<Foam::particleDiffusivityModel> Foam::particleDiffusivityModel::New
(
    particleModel& model,
    const dictionary& dict
)
{
    word particleDiffusivityModelType(dict.lookup("type"));

    Info<< "Selecting Brownian diffusivity model" << endl;

    dictionaryConstructorTable::iterator cstrIter =
        dictionaryConstructorTablePtr_->find(particleDiffusivityModelType);

    if (cstrIter == dictionaryConstructorTablePtr_->end())
    {
        FatalErrorInFunction
            << "Unknown particle diffusivity model "
            << particleDiffusivityModelType << endl << endl
            << "Valid particle diffusivity models are : " << endl
            << dictionaryConstructorTablePtr_->sortedToc()
            << exit(FatalError);
    }

    return cstrIter()(model, dict);
}

bool Foam::particleDiffusivityModel::writeData(Ostream& os) const
{
    return os.good();
}

// ************************************************************************* //
