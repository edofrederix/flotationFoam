#ifndef capturedParticleSection_H
#define capturedParticleSection_H

#include "autoPtr.H"
#include "volFields.H"
#include "particleSection.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// Forward declarations
class flotationSystem;

/*---------------------------------------------------------------------------*\
                   Class capturedParticleSection Declaration
\*---------------------------------------------------------------------------*/

class capturedParticleSection
:
    public particleSection
{
public:

    // Constructors

        capturedParticleSection
        (
            const label sectionNum,
            const flotationSystem& system
        );


    //- Destructor
    virtual ~capturedParticleSection();


    // Member Functions

        word particleType() const
        {
            return "captured";
        }

        word particleTypeShort() const
        {
            return "c";
        }
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
