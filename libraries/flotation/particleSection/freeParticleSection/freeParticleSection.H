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
    // Private data

        //- Free particle velocity field
        autoPtr<volVectorField> V_;

        //- Free particle flux field
        surfaceScalarField phi_;

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

        //- Return the free particle velocity field
        inline volVectorField& V()
        {
            return V_();
        }

        inline const volVectorField& V() const
        {
            return V_();
        }

        //- Return the free particle flux field
        inline surfaceScalarField& phi()
        {
            return phi_;
        }

        inline const surfaceScalarField& phi() const
        {
            return phi_;
        }

        //- Provide the particle type
        word particleType()
        {
            return "free";
        }

        word particleTypeShort()
        {
            return "f";
        }

        virtual void read();
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
