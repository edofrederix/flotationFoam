#ifndef PotentialFlowSherwood_H
#define PotentialFlowSherwood_H

#include "SherwoodCorrelation.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace SherwoodCorrelations
{

/*---------------------------------------------------------------------------*\
                           Class PotentialFlowSherwood Declaration
\*---------------------------------------------------------------------------*/

class PotentialFlowSherwood
:
    public SherwoodCorrelation
{
public:

    //- Runtime type information
    TypeName("PotentialFlow");


    // Constructors

        //- Construct from a dictionary and a mesh
        PotentialFlowSherwood
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system
        );


    //- Destructor
    virtual ~PotentialFlowSherwood();


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
