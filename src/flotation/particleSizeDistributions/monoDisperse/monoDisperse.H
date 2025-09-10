#ifndef monoDisperse_H
#define monoDisperse_H

#include "particleSizeDistribution.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace particleSizeDistributions
{

/*---------------------------------------------------------------------------*\
                           Class monoDisperse Declaration
\*---------------------------------------------------------------------------*/

class monoDisperse
:
    public particleSizeDistribution
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

} // End namespace particleSizeDistributions
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
