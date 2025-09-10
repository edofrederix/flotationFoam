#ifndef dispersedTurbulentDeposition_H
#define dispersedTurbulentDeposition_H

#include "dispersedParticleTransferModel.H"
#include "dispersedPhaseInterface.H"
#include "dispersedTurbulentDepositionRate.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace particleTransferModels
{

/*---------------------------------------------------------------------------*\
                     Class dispersedTurbulentDeposition Declaration
\*---------------------------------------------------------------------------*/

class dispersedTurbulentDeposition
:
    public dispersedParticleTransferModel
{
protected:

    //- Dispersed deposition rate model
    autoPtr<dispersedTurbulentDepositionRate> rate_;

public:

    //- Runtime type information
    TypeName("dispersedTurbulentDeposition");

    // Constructors

        dispersedTurbulentDeposition
        (
            const particleModel& model,
            const dictionary& dict
        );


    //- Destructor
    virtual ~dispersedTurbulentDeposition()
    {}


    // Member Functions

        // Transfer coefficient
        virtual tmp<volScalarField> K(volScalarField& N) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace particleTransferModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
