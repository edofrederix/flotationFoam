#ifndef RanzMarshallSh_H
#define RanzMarshallSh_H

#include "SherwoodNumber.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace SherwoodNumbers
{

/*---------------------------------------------------------------------------*\
                    Class RanzMarshallSherwoodNumber Declaration
\*---------------------------------------------------------------------------*/

class RanzMarshallSherwoodNumber
:
    public SherwoodNumber
{
public:

    //- Runtime type information
    TypeName("RanzMarshall");


    // Constructors

        //- Construct from mesh and type
        RanzMarshallSherwoodNumber
        (
            const fvMesh& mesh,
            const word type
        );


    //- Destructor
    virtual ~RanzMarshallSherwoodNumber();


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
