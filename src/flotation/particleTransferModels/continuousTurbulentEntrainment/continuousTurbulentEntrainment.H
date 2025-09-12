#ifndef continuousTurbulentEntrainment_H
#define continuousTurbulentEntrainment_H

#include "continuousParticleTransferModel.H"
#include "continuousTurbulentEntrainmentRate.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace particleTransferModels
{

/*---------------------------------------------------------------------------*\
                     Class continuousTurbulentEntrainment Declaration
\*---------------------------------------------------------------------------*/

class continuousTurbulentEntrainment
:
    public continuousParticleTransferModel
{
protected:

    //- Continuous entrainment rate model
    autoPtr<continuousTurbulentEntrainmentRate> rate_;

public:

    //- Runtime type information
    TypeName("continuousTurbulentEntrainment");

    // Constructors

        continuousTurbulentEntrainment
        (
            const particleModel& model,
            const dictionary& dict
        );


    //- Destructor
    virtual ~continuousTurbulentEntrainment()
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
