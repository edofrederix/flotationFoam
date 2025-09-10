#ifndef continuousEntrainment_H
#define continuousEntrainment_H

#include "continuousParticleTransferModel.H"
#include "continuousEntrainmentRate.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace particleTransferModels
{

/*---------------------------------------------------------------------------*\
                     Class continuousEntrainment Declaration
\*---------------------------------------------------------------------------*/

class continuousEntrainment
:
    public continuousParticleTransferModel
{
protected:

    //- Continuous entrainment rate model
    autoPtr<continuousEntrainmentRate> rate_;

public:

    //- Runtime type information
    TypeName("continuousEntrainment");

    // Constructors

        continuousEntrainment
        (
            const particleModel& model,
            const dictionary& dict
        );


    //- Destructor
    virtual ~continuousEntrainment()
    {}


    // Member Functions

        // Return the source term
        virtual tmp<fvScalarMatrix> R(volScalarField& N) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace particleTransferModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
