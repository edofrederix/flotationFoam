#ifndef RanzMarshallSherwood_H
#define RanzMarshallSherwood_H

#include "SherwoodCorrelation.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace SherwoodCorrelations
{

/*---------------------------------------------------------------------------*\
                           Class RanzMarshallSherwood Declaration
\*---------------------------------------------------------------------------*/

class RanzMarshallSherwood
:
    public SherwoodCorrelation
{
public:

    //- Runtime type information
    TypeName("RanzMarshall");


    // Constructors

        //- Construct from a dictionary and a mesh
        RanzMarshallSherwood
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system
        );


    //- Destructor
    virtual ~RanzMarshallSherwood();


    // Member Functions

        //- Sherwood number given the bubble Peclet and Reynolds number
        virtual tmp<volScalarField> Sh
        (
            const volScalarField& Pe,
            const volScalarField& Re
        ) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace SherwoodCorrelations
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
