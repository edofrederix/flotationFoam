#ifndef DaiInductionTime_H
#define DaiInductionTime_H

#include "inductionTime.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace particleTransferModels
{

namespace inductionTimes
{

/*---------------------------------------------------------------------------*\
                        Class DaiInductionTime Declaration
\*---------------------------------------------------------------------------*/

class DaiInductionTime
:
    public inductionTime
{
    // Private data

        //- Model coefficients
        scalar A_;
        scalar B_;

public:

    //- Runtime type information
    TypeName("Dai");


    // Constructors

        //- Construct from a dictionary and a mesh
        DaiInductionTime
        (
            dispersedInterception& transfer,
            const dictionary& dict
        );


    //- Destructor
    virtual ~DaiInductionTime();


    // Member Functions

        // Induction time
        virtual dimensionedScalar t(const volScalarField& N) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace inductionTimes
} // End namespace particleTransferModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
