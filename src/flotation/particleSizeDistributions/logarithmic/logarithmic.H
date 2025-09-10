#ifndef logarithmic_H
#define logarithmic_H

#include "particleSizeDistribution.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace particleSizeDistributions
{

/*---------------------------------------------------------------------------*\
                           Class logarithmic Declaration
\*---------------------------------------------------------------------------*/

class logarithmic
:
    public particleSizeDistribution
{
    // Private data


public:

    //- Runtime type information
    TypeName("logarithmic");


    // Constructors

        //- Construct from a dictionary and a mesh
        logarithmic
        (
            const dictionary& dict,
            const fvMesh& mesh,
            const bool registerObject
        );


    //- Destructor
    virtual ~logarithmic();


    // Member Functions

};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace particleSizeDistributions
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
