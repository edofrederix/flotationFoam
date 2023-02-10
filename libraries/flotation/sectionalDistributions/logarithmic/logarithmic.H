#ifndef logarithmic_H
#define logarithmic_H

#include "sectionalDistribution.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace sectionalDistributions
{

/*---------------------------------------------------------------------------*\
                           Class logarithmic Declaration
\*---------------------------------------------------------------------------*/

class logarithmic
:
    public sectionalDistribution
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

} // End namespace sectionalDistributions
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
