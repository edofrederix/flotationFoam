#ifndef monoDisperse_H
#define monoDisperse_H

#include "sectionalDistribution.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace sectionalDistributions
{

/*---------------------------------------------------------------------------*\
                           Class monoDisperse Declaration
\*---------------------------------------------------------------------------*/

class monoDisperse
:
    public sectionalDistribution
{
    // Private data


public:

    //- Runtime type information
    TypeName("monoDisperse");


    // Constructors

        //- Construct from a dictionary and a mesh
        monoDisperse
        (
            const dictionary& dict,
            const fvMesh& mesh,
            const bool registerObject
        );


    //- Destructor
    virtual ~monoDisperse();


    // Member Functions

};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace sectionalDistributions
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
