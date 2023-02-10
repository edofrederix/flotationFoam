#ifndef StokesFlowSherwood_H
#define StokesFlowSherwood_H

#include "SherwoodCorrelation.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace SherwoodCorrelations
{

/*---------------------------------------------------------------------------*\
                           Class StokesFlowSherwood Declaration
\*---------------------------------------------------------------------------*/

class StokesFlowSherwood
:
    public SherwoodCorrelation
{
public:

    //- Runtime type information
    TypeName("StokesFlow");


    // Constructors

        //- Construct from a dictionary and a mesh
        StokesFlowSherwood
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system
        );


    //- Destructor
    virtual ~StokesFlowSherwood();


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
