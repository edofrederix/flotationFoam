#ifndef sectionalList_H
#define sectionalList_H

#include "sectionalDistribution.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace sectionalDistributions
{

/*---------------------------------------------------------------------------*\
                           Class sectionalList Declaration
\*---------------------------------------------------------------------------*/

class sectionalList
:
    public sectionalDistribution
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

} // End namespace sectionalDistributions
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
