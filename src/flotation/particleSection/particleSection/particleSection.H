#ifndef particleSection_H
#define particleSection_H

#include "volFields.H"
#include "surfaceFields.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// Forward declarations
class flotationSystem;

/*---------------------------------------------------------------------------*\
                        Class particleSection Declaration
\*---------------------------------------------------------------------------*/

class particleSection
{
    // Private data

protected:

    // Protected data

        //- Sectional index
        const label sectionNum_;

        //- Flotation particle system
        const flotationSystem& system_;

        //- Particle section number concentration field
        autoPtr<volScalarField> N_;

        //- Particle velocity flux field
        autoPtr<surfaceScalarField> phi_;

        //- Actual particle flux field
        autoPtr<surfaceScalarField> phiN_;


public:

    // Constructors

        particleSection
        (
            const label sectionNum,
            const flotationSystem& system
        );


    //- Destructor
    virtual ~particleSection();


    // Member Functions

        //- Return the sectional name
        word sectionName() const;

        //- Read the particle concentration field
        virtual void read();

        //- Return the particle section number concentration field
        inline volScalarField& N()
        {
            return N_();
        }

        inline const volScalarField& N() const
        {
            return N_();
        }

        //- Return the particle velocity flux field
        inline surfaceScalarField& phi()
        {
            return phi_();
        }

        inline const surfaceScalarField& phi() const
        {
            return phi_();
        }

        //- Return the actual particle flux field
        inline surfaceScalarField& phiN()
        {
            return phiN_();
        }

        inline const surfaceScalarField& phiN() const
        {
            return phiN_();
        }

        //- Return the sectional number
        inline const label& sectionNum() const
        {
            return sectionNum_;
        }

        //- Return the particle velocity, calculated from the velocity flux
        virtual tmp<volVectorField> V() const;

        //- Return the particle type
        virtual word particleType() const = 0;

        //- Return the particle type
        virtual word particleTypeShort() const = 0;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
