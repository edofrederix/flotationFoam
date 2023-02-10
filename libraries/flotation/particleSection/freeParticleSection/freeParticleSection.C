#include "freeParticleSection.H"
#include "particleSection.H"
#include "flotationSystem.H"

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::freeParticleSection::freeParticleSection
(
    const label sectionNum,
    const flotationSystem& system
)
:
    particleSection(sectionNum, system),
    phi_
    (
        IOobject
        (
            IOobject::groupName("phi"+particleTypeShort(), sectionName()),
            system_.mesh().time().timeName(),
            system_.mesh(),
            IOobject::NO_READ,
            IOobject::NO_WRITE
        ),
        system_.mesh(),
        dimensionedScalar
        (
            IOobject::groupName("phi"+particleTypeShort(), sectionName()),
            dimVelocity*dimArea,
            0.0
        )
    )
{
    this->read();
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::freeParticleSection::~freeParticleSection()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void Foam::freeParticleSection::read()
{
    particleSection::read();

    IOobject fieldHeader
    (
        IOobject::groupName("V"+particleTypeShort(), sectionName()),
        system_.mesh().time().timeName(),
        system_.mesh(),
        IOobject::NO_READ
    );

    IOobject defaultFieldHeader
    (
        "V"+particleTypeShort(),
        system_.mesh().time().timeName(),
        system_.mesh(),
        IOobject::NO_READ
    );

    if (fieldHeader.headerOk())
    {
        V_.set
        (
            new volVectorField
            (
                IOobject
                (
                    IOobject::groupName("V"+particleTypeShort(), sectionName()),
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
        tmp<volVectorField> tdefaultField
        (
            new volVectorField
            (
                IOobject
                (
                    "V"+particleTypeShort(),
                    system_.mesh().time().timeName(),
                    system_.mesh(),
                    IOobject::MUST_READ,
                    IOobject::NO_WRITE
                ),
                system_.mesh()
            )
        );

        V_.set
        (
            new volVectorField
            (
                IOobject
                (
                    IOobject::groupName("V"+particleTypeShort(), sectionName()),
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
            << "Field " << IOobject::groupName("V"+particleTypeShort(), sectionName())
            << " not found (not the field itself, nor a default field named "
            << "V"+particleTypeShort() << ")."
            << abort(FatalError);
    }
}

// ************************************************************************* //
