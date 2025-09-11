#ifndef continuousParticleTransferModel_H
#define continuousParticleTransferModel_H

#include "particleTransferModel.H"
#include "dispersedPhaseInterface.H"
#include "blendingMethod.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace particleTransferModels
{

/*---------------------------------------------------------------------------*\
                Class continuousParticleTransferModel Declaration
\*---------------------------------------------------------------------------*/

class continuousParticleTransferModel
:
    public particleTransferModel
{
protected:

    // Protected Data

        //- Dispersed phase interface. The phase of the particle model is
        //  considered to be the dispersed phase.
        dispersedPhaseInterface interface_;

        //- Blending method
        autoPtr<blendingMethod> blending_;

public:

    // Constructors

        continuousParticleTransferModel
        (
            const particleModel& model,
            const dictionary& dict
        );


    //- Destructor
    virtual ~continuousParticleTransferModel()
    {}


    // Member Functions

        // Return the dispersed interface
        inline const dispersedPhaseInterface& interface() const
        {
            return interface_;
        }

        // Transfer coefficient
        virtual tmp<volScalarField> K(volScalarField& N) const = 0;

        // Return the source term
        virtual tmp<fvScalarMatrix> R(volScalarField& N) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace particleTransferModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
