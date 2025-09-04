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
    particleSection(sectionNum, system),
    V_(system.twoPhasePair().dispersed().U()),
    phi_(system.twoPhasePair().dispersed().phi())
{
    this->read();
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::capturedParticleSection::~capturedParticleSection()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

// ************************************************************************* //
