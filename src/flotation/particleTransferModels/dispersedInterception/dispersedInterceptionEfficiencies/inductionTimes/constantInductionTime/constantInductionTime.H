#ifndef constantInductionTime_H
#define constantInductionTime_H

#include "inductionTime.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace particleTransferModels
{

namespace inductionTimes
{

/*---------------------------------------------------------------------------*\
                           Class constantInductionTime Declaration
\*---------------------------------------------------------------------------*/

class constantInductionTime
:
    public inductionTime
{
    // Private data

        //- Constant induction time value
        scalar t_;

public:

    //- Runtime type information
    TypeName("constant");


    // Constructors

        //- Construct from a dictionary and a mesh
        constantInductionTime
        (
            dispersedInterception& transfer,
            const dictionary& dict
        );


    //- Destructor
    virtual ~constantInductionTime();


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
