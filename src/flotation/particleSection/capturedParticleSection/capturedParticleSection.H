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
    // Private data

        //- Captured particle velocity
        const volVectorField& V_;

        //- Captured particle flux
        const surfaceScalarField& phi_;

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

        //- Return the captured particle velocity field
        inline const volVectorField& V() const
        {
            return V_;
        }

        //- Return the captured particle flux field
        inline const surfaceScalarField& phi() const
        {
            return phi_;
        }

        word particleType()
        {
            return "captured";
        }

        word particleTypeShort()
        {
            return "c";
        }
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
