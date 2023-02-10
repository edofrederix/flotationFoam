#ifndef constantSherwood_H
#define constantSherwood_H

#include "SherwoodCorrelation.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace SherwoodCorrelations
{

/*---------------------------------------------------------------------------*\
                           Class constantSherwood Declaration
\*---------------------------------------------------------------------------*/

class constantSherwood
:
    public SherwoodCorrelation
{
    // Private data

        //- Constant Sherwood number
        scalar Sh_;

public:

    //- Runtime type information
    TypeName("constant");


    // Constructors

        //- Construct from a dictionary and a mesh
        constantSherwood
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system
        );


    //- Destructor
    virtual ~constantSherwood();


    // Member Functions

        //- Sherwood number given the bubble Reynolds number and Schmidt number
        virtual tmp<volScalarField> Sh
        (
            const volScalarField& Re,
            const volScalarField& Sc
        ) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace SherwoodCorrelations
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
