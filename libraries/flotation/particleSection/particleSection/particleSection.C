#include "particleSection.H"
#include "flotationSystem.H"

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::particleSection::particleSection
(
    const label sectionNum,
    const flotationSystem& system
)
:
    sectionNum_(sectionNum),
    system_(system)
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::particleSection::~particleSection()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::word Foam::particleSection::sectionName() const
{
    return system_.distribution().sectionName(sectionNum_);
}

void Foam::particleSection::read()
{
    IOobject fieldHeader
    (
        IOobject::groupName("N"+particleTypeShort(), sectionName()),
        system_.mesh().time().timeName(),
        system_.mesh(),
        IOobject::NO_READ
    );

    IOobject defaultFieldHeader
    (
        "N"+particleTypeShort(),
        system_.mesh().time().timeName(),
        system_.mesh(),
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
                    IOobject::groupName("N"+particleTypeShort(), sectionName()),
                    system_.mesh().time().timeName(),
                    system_.mesh(),
                    IOobject::MUST_READ,
                    IOobject::AUTO_WRITE
                ),
                system_.mesh()
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
                    "N"+particleTypeShort(),
                    system_.mesh().time().timeName(),
                    system_.mesh(),
                    IOobject::MUST_READ,
                    IOobject::NO_WRITE
                ),
                system_.mesh()
            )
        );

        N_.set
        (
            new volScalarField
            (
                IOobject
                (
                    IOobject::groupName("N"+particleTypeShort(), sectionName()),
                    system_.mesh().time().timeName(),
                    system_.mesh(),
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
            << "Field " << IOobject::groupName("N"+particleTypeShort(), sectionName())
            << " not found (not the field itself, nor a default field named "
            << "N"+particleTypeShort() << ")."
            << abort(FatalError);
    }

    system_.mesh().schemes().setFluxRequired(N_->name());

    Phi_.set
    (
        new surfaceScalarField
        (
            IOobject
            (
                IOobject::groupName("Phi"+particleTypeShort(), sectionName()),
                system_.mesh().time().timeName(),
                system_.mesh(),
                IOobject::NO_READ,
                IOobject::NO_WRITE
            ),
            system_.mesh(),
            dimensionedScalar
            (
                IOobject::groupName("Phi"+particleTypeShort(), sectionName()),
                dimVelocity*dimArea/dimVolume,
                0.0
            )
        )
    );
}

// ************************************************************************* //
