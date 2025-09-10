#ifndef potentialFlowSh_H
#define potentialFlowSh_H

#include "SherwoodNumber.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace SherwoodNumbers
{

/*---------------------------------------------------------------------------*\
                  Class potentialFlowSherwoodNumber Declaration
\*---------------------------------------------------------------------------*/

class potentialFlowSherwoodNumber
:
    public SherwoodNumber
{
public:

    //- Runtime type information
    TypeName("potentialFlow");


    // Constructors

        //- Construct from mesh and type
        potentialFlowSherwoodNumber
        (
            const fvMesh& mesh,
            const word type
        );


    //- Destructor
    virtual ~potentialFlowSherwoodNumber();


    // Member Functions

        //- SherwoodNumber number given the bubble Peclet and Reynolds number
        virtual tmp<volScalarField> Sh
        (
            const volScalarField& Pe,
            const volScalarField& Re
        ) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace SherwoodNumbers
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
