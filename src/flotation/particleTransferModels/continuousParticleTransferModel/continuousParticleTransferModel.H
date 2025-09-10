#ifndef continuousParticleTransferModel_H
#define continuousParticleTransferModel_H

#include "particleTransferModel.H"
#include "dispersedPhaseInterface.H"

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

    //- Dispersed phase interface. The phase of the particle model is considered
    //  to be the dispersed phase.
    dispersedPhaseInterface interface_;

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
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace particleTransferModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
