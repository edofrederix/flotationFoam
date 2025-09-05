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
    particleSection(sectionNum, system)
{
    this->read();
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::freeParticleSection::~freeParticleSection()
{}

// ************************************************************************* //
