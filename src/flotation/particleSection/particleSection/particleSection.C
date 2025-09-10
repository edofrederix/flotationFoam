#include "particleSection.H"
#include "particleModel.H"
#include "flotationSystem.H"
#include "fvcReconstruct.H"

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::particleSection::particleSection
(
    const label sectionNum,
    const particleModel& model
)
:
    sectionNum_(sectionNum),
    model_(model)
{
    read();
}

// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::particleSection::~particleSection()
{}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::word Foam::particleSection::sectionName() const
{
    return model_.system().distribution().sectionName(sectionNum_);
}

void Foam::particleSection::read()
{
    const word defaultFieldName =
        IOobject::groupName("N", model_.phase().name());

    const word fieldName = defaultFieldName + ":" + sectionName();

    IOobject fieldHeader
    (
        fieldName,
        model_.system().mesh().time().time().name(),
        model_.system().mesh(),
        IOobject::NO_READ
    );

    IOobject defaultFieldHeader
    (
        defaultFieldName,
        model_.system().mesh().time().time().name(),
        model_.system().mesh(),
        IOobject::NO_READ
    );

    if (fieldHeader.headerOk())
    {
        N_.set
        (
            new volScalarField
            (
                IOobject
                (
                    fieldName,
                    model_.system().mesh().time().time().name(),
                    model_.system().mesh(),
                    IOobject::MUST_READ,
                    IOobject::AUTO_WRITE
                ),
                model_.system().mesh()
            )
        );
    }
    else if (defaultFieldHeader.headerOk())
    {
        tmp<volScalarField> tdefaultField
        (
            new volScalarField
            (
                IOobject
                (
                    defaultFieldName,
                    model_.system().mesh().time().time().name(),
                    model_.system().mesh(),
                    IOobject::MUST_READ,
                    IOobject::NO_WRITE
                ),
                model_.system().mesh()
            )
        );

        N_.set
        (
            new volScalarField
            (
                IOobject
                (
                    fieldName,
                    model_.system().mesh().time().time().name(),
                    model_.system().mesh(),
                    IOobject::NO_READ,
                    IOobject::AUTO_WRITE
                ),
                tdefaultField()
            )
        );
    }
    else
    {
        FatalErrorInFunction
            << "Field " << fieldName << " not found "
            << "(not the field itself, nor a default field named "
            << defaultFieldName << ")."
            << abort(FatalError);
    }

    model_.system().mesh().schemes().setFluxRequired(N_->name());

    D_.set
    (
        new volScalarField
        (
            IOobject
            (
                IOobject::groupName("D", model_.phase().name())
              + ":"
              + sectionName(),
                model_.system().mesh().time().time().name(),
                model_.system().mesh(),
                IOobject::NO_READ,
                IOobject::NO_WRITE
            ),
            model_.system().mesh(),
            dimensionedScalar(dimArea/dimTime, 0.0)
        )
    );

    phi_.set
    (
        new surfaceScalarField
        (
            IOobject
            (
                IOobject::groupName("phi", model_.phase().name())
              + ":"
              + sectionName(),
                model_.system().mesh().time().time().name(),
                model_.system().mesh(),
                IOobject::NO_READ,
                IOobject::NO_WRITE
            ),
            model_.system().mesh(),
            dimensionedScalar(dimVelocity*dimArea, 0.0)
        )
    );

    phiN_.set
    (
        new surfaceScalarField
        (
            IOobject
            (
                IOobject::groupName("phiN", model_.phase().name())
              + ":"
              + sectionName(),
                model_.system().mesh().time().time().name(),
                model_.system().mesh(),
                IOobject::NO_READ,
                IOobject::NO_WRITE
            ),
            model_.system().mesh(),
            dimensionedScalar(dimVelocity*dimArea/dimVolume, 0.0)
        )
    );
}

Foam::tmp<Foam::volVectorField> Foam::particleSection::V() const
{
    tmp<volVectorField> tV(fvc::reconstruct(phi()));

    tV->rename
    (
        IOobject::groupName("V", model_.phase().name())
      + ":"
      + sectionName()
    );

    return tV;
}

// ************************************************************************* //
