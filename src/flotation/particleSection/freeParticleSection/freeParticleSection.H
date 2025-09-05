#ifndef freeParticleSection_H
#define freeParticleSection_H

#include "autoPtr.H"
#include "volFields.H"
#include "surfaceFields.H"
#include "particleSection.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                        Class freeParticleSection Declaration
\*---------------------------------------------------------------------------*/

class freeParticleSection
:
    public particleSection
{
public:

    // Constructors

        freeParticleSection
        (
            const label sectionNum,
            const flotationSystem& system
        );


    //- Destructor
    virtual ~freeParticleSection();


    // Member Functions

        //- Provide the particle type
        word particleType() const
        {
            return "free";
        }

        word particleTypeShort() const
        {
            return "f";
        }
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
