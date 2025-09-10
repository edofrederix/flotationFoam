#ifndef dispersedInterception_H
#define dispersedInterception_H

#include "dispersedParticleTransferModel.H"
#include "dispersedInterceptionEfficiency.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace particleTransferModels
{

/*---------------------------------------------------------------------------*\
                     Class dispersedInterception Declaration
\*---------------------------------------------------------------------------*/

class dispersedInterception
:
    public dispersedParticleTransferModel
{
protected:

    //- Efficiency model
    autoPtr<dispersedInterceptionEfficiency> efficiency_;


public:

    //- Runtime type information
    TypeName("dispersedInterception");

    // Constructors

        dispersedInterception
        (
            const particleModel& model,
            const dictionary& dict
        );


    //- Destructor
    virtual ~dispersedInterception()
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
