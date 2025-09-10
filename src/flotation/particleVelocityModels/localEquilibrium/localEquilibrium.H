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
            particleModel& model,
            const dictionary& dict
        );


    //- Destructor
    virtual ~localEquilibrium();


    // Member Functions

        //- Correct the particle velocities
        virtual void correct();
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace particleVelocityModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
