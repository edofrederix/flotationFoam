#ifndef continuousBrownianEntrainment_H
#define continuousBrownianEntrainment_H

#include "continuousParticleTransferModel.H"
#include "SherwoodNumber.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace particleTransferModels
{

/*---------------------------------------------------------------------------*\
                     Class continuousBrownianEntrainment Declaration
\*---------------------------------------------------------------------------*/

class continuousBrownianEntrainment
:
    public continuousParticleTransferModel
{
protected:

    // Protected Data

        //- Sherwood number correlation
        autoPtr<Foam::SherwoodNumber> Sh_;

public:

    //- Runtime type information
    TypeName("continuousBrownianEntrainment");

    // Constructors

        continuousBrownianEntrainment
        (
            const particleModel& model,
            const dictionary& dict
        );


    //- Destructor
    virtual ~continuousBrownianEntrainment()
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
