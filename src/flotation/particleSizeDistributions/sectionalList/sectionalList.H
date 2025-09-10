#ifndef sectionalList_H
#define sectionalList_H

#include "particleSizeDistribution.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace particleSizeDistributions
{

/*---------------------------------------------------------------------------*\
                           Class sectionalList Declaration
\*---------------------------------------------------------------------------*/

class sectionalList
:
    public particleSizeDistribution
{
    // Private data


public:

    //- Runtime type information
    TypeName("sectionalList");


    // Constructors

        //- Construct from a dictionary and a mesh
        sectionalList
        (
            const dictionary& dict,
            const fvMesh& mesh,
            const bool registerObject
        );


    //- Destructor
    virtual ~sectionalList();


    // Member Functions

};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace particleSizeDistributions
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
