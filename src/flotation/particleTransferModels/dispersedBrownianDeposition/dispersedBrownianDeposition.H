#ifndef dispersedBrownianDeposition_H
#define dispersedBrownianDeposition_H

#include "dispersedParticleTransferModel.H"
#include "SherwoodNumber.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace particleTransferModels
{

/*---------------------------------------------------------------------------*\
                     Class dispersedBrownianDeposition Declaration
\*---------------------------------------------------------------------------*/

class dispersedBrownianDeposition
:
    public dispersedParticleTransferModel
{
protected:

    // Protected Data

        //- Sherwood number correlation
        autoPtr<Foam::SherwoodNumber> Sh_;

public:

    //- Runtime type information
    TypeName("dispersedBrownianDeposition");

    // Constructors

        dispersedBrownianDeposition
        (
            const particleModel& model,
            const dictionary& dict
        );


    //- Destructor
    virtual ~dispersedBrownianDeposition()
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
