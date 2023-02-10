#ifndef flotation_H
#define flotation_H

#include "fvModel.H"
#include "flotationSystem.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace fv
{

/*---------------------------------------------------------------------------*\
                Class flotation Declaration
\*---------------------------------------------------------------------------*/

class flotation
:
    public fvModel
{
    // Private data

        //- Particle flotation system
        flotationSystem system_;


public:

    //- Runtime type information
    TypeName("flotation");


    // Constructors

        //- Construct from dictionary
        flotation
        (
            const word& name,
            const word& modelType,
            const dictionary& dict,
            const fvMesh& mesh
        );


    //- Destructor
    virtual ~flotation();


    // Member Functions

        // Correction

            //- Correct the model
            virtual void correct();

        // Mesh changes

            //- Update for mesh motion
            virtual bool movePoints();

            //- Update topology using the given map
            virtual void topoChange(const polyTopoChangeMap&);

            //- Update from another mesh using the given map
            virtual void mapMesh(const polyMeshMap&);

            //- Redistribute or update using the given distribution map
            virtual void distribute(const polyDistributionMap&);

        // IO

            //- Read dictionary
            virtual bool read(const dictionary& dict);
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace fv
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
