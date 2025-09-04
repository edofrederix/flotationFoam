#ifndef localEquilibrium_H
#define localEquilibrium_H

#include "particleVelocityModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace particleVelocityModels
{

/*---------------------------------------------------------------------------*\
                           Class localEquilibrium Declaration
\*---------------------------------------------------------------------------*/

class localEquilibrium
:
    public particleVelocityModel
{
    // Private data


public:

    //- Runtime type information
    TypeName("localEquilibrium");


    // Constructors

        //- Construct from a dictionary and a mesh
        localEquilibrium
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system,
            const bool registerObject
        );


    //- Destructor
    virtual ~localEquilibrium();


    // Member Functions

        //- Update the particle velocities
        virtual void update();
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace particleVelocityModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
