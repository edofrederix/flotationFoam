#ifndef dispersedParticleTransferModel_H
#define dispersedParticleTransferModel_H

#include "particleTransferModel.H"
#include "dispersedPhaseInterface.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace particleTransferModels
{

/*---------------------------------------------------------------------------*\
                Class dispersedParticleTransferModel Declaration
\*---------------------------------------------------------------------------*/

class dispersedParticleTransferModel
:
    public particleTransferModel
{
protected:

    // Protected Data

        //- Dispersed phase interface. The phase of the particle model is
        //  considered to be the continuous phase.
        dispersedPhaseInterface interface_;

public:

    // Constructors

        dispersedParticleTransferModel
        (
            const particleModel& model,
            const dictionary& dict
        );


    //- Destructor
    virtual ~dispersedParticleTransferModel()
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
