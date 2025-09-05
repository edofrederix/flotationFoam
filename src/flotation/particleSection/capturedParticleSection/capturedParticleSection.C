#include "capturedParticleSection.H"
#include "particleSection.H"
#include "flotationSystem.H"

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::capturedParticleSection::capturedParticleSection
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

Foam::capturedParticleSection::~capturedParticleSection()
{}

// ************************************************************************* //
