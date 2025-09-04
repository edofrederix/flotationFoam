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

        //- Particle section effective flux field
        autoPtr<surfaceScalarField> Phi_;


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

        //- Return the particle section effective flux field
        inline surfaceScalarField& Phi()
        {
            return Phi_();
        }

        inline const surfaceScalarField& Phi() const
        {
            return Phi_();
        }

        //- Return the sectional number
        inline const label& sectionNum() const
        {
            return sectionNum_;
        }

        //- Return the particle type
        virtual word particleType() = 0;

        //- Return the particle type
        virtual word particleTypeShort() = 0;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
