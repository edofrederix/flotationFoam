#ifndef constantSh_H
#define constantSh_H

#include "SherwoodNumber.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace SherwoodNumbers
{

/*---------------------------------------------------------------------------*\
                     Class constantSherwoodNumber Declaration
\*---------------------------------------------------------------------------*/

class constantSherwoodNumber
:
    public SherwoodNumber
{
    // Private data

        //- Constant SherwoodNumber number
        scalar Sh_;

public:

    //- Runtime type information
    TypeName("constant");


    // Constructors

        //- Construct from mesh and type
        constantSherwoodNumber
        (
            const fvMesh& mesh,
            const word type
        );

        //- Construct from mesh and value
        constantSherwoodNumber
        (
            const fvMesh& mesh,
            const scalar value
        );


    //- Destructor
    virtual ~constantSherwoodNumber();


    // Member Functions

        //- SherwoodNumber number given the bubble Reynolds number and Schmidt number
        virtual tmp<volScalarField> Sh
        (
            const volScalarField& Re,
            const volScalarField& Sc
        ) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace SherwoodNumbers
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
