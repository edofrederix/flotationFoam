#ifndef particleVelocityModel_H
#define particleVelocityModel_H

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "dictionary.H"
#include "runTimeSelectionTables.H"
#include "fvMesh.H"

namespace Foam
{

// Forward declarations
class flotationSystem;

/*---------------------------------------------------------------------------*\
                    Class particleVelocityModel Declaration
\*---------------------------------------------------------------------------*/

class particleVelocityModel
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
    TypeName("particleVelocityModel");


    // Declare runtime construction

        declareRunTimeSelectionTable
        (
            autoPtr,
            particleVelocityModel,
            dictionary,
            (
                const dictionary& dict,
                const fvMesh& mesh,
                flotationSystem& system,
                const bool registerObject
            ),
            (dict, mesh, system, registerObject)
        );


    // Static data members


    // Constructors

        particleVelocityModel
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system,
            const bool registerObject
        );


    //- Destructor
    virtual ~particleVelocityModel();


    // Selectors

        static autoPtr<particleVelocityModel> New
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system
        );


    // Member Functions

        //- Dummy write for regIOobject
        bool writeData(Ostream& os) const;

        //- Update the particle velocities
        virtual void update() = 0;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
