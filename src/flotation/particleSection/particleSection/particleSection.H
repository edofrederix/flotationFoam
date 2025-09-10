#ifndef particleSection_H
#define particleSection_H

#include "volFields.H"
#include "surfaceFields.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// Forward declarations
class particleModel;

/*---------------------------------------------------------------------------*\
                        Class particleSection Declaration
\*---------------------------------------------------------------------------*/

class particleSection
{
protected:

    // Protected data

        //- Sectional index
        const label sectionNum_;

        //- Particle model
        const particleModel& model_;

        //- Particle section number concentration field
        autoPtr<volScalarField> N_;

        //- Particle diffusivity
        autoPtr<volScalarField> D_;

        //- Particle velocity flux field
        autoPtr<surfaceScalarField> phi_;

        //- Actual particle flux field
        autoPtr<surfaceScalarField> phiN_;


public:

    // Constructors

        particleSection
        (
            const label sectionNum,
            const particleModel& model
        );


    //- Destructor
    virtual ~particleSection();


    // Member Functions

        //- Return the section name
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

        //- Return the particle diffusivity
        inline volScalarField& D()
        {
            return D_();
        }

        inline const volScalarField& D() const
        {
            return D_();
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

        //- Return the section number
        inline label sectionNum() const
        {
            return sectionNum_;
        }

        //- Return the particle velocity, calculated from the velocity flux
        virtual tmp<volVectorField> V() const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
