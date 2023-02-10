#ifndef passiveTracer_H
#define passiveTracer_H

#include "particleVelocityModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace particleVelocityModels
{

/*---------------------------------------------------------------------------*\
                           Class passiveTracer Declaration
\*---------------------------------------------------------------------------*/

class passiveTracer
:
    public particleVelocityModel
{
    // Private data


public:

    //- Runtime type information
    TypeName("passiveTracer");


    // Constructors

        //- Construct from a dictionary and a mesh
        passiveTracer
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system,
            const bool registerObject
        );


    //- Destructor
    virtual ~passiveTracer();


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
