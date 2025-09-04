#ifndef interactionModel_H
#define interactionModel_H

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "dictionary.H"
#include "fvMesh.H"

namespace Foam
{

// Forward declarations
class flotationSystem;

/*---------------------------------------------------------------------------*\
                    Class interactionModel Declaration
\*---------------------------------------------------------------------------*/

class interactionModel
:
    public regIOobject
{
protected:

    // Protected data

        //- Reference to the mesh
        const fvMesh& mesh_;

        //- Reference to the FPS object
        flotationSystem& system_;

        //- Reference to the dictionary
        const dictionary& dict_;


public:

    //- Runtime type information
    TypeName("interactionModel");


    // Constructors

        interactionModel
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system,
            const bool registerObject,
            const word subTypeName,
            const word subSubTypeName
        );


    //- Destructor
    virtual ~interactionModel();

    // Member Functions

        //- Dummy write for regIOobject
        bool writeData(Ostream& os) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
