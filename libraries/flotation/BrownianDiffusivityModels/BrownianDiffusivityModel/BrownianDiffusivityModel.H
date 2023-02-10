#ifndef BrownianDiffusivityModel_H
#define BrownianDiffusivityModel_H

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "dictionary.H"
#include "runTimeSelectionTables.H"
#include "fvMesh.H"

namespace Foam
{

// Forward declarations
class flotationSystem;

/*---------------------------------------------------------------------------*\
                    Class BrownianDiffusivityModel Declaration
\*---------------------------------------------------------------------------*/

class BrownianDiffusivityModel
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
    TypeName("BrownianDiffusivityModel");


    // Declare runtime construction

        declareRunTimeSelectionTable
        (
            autoPtr,
            BrownianDiffusivityModel,
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

        BrownianDiffusivityModel
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system,
            const bool registerObject
        );


    //- Destructor
    virtual ~BrownianDiffusivityModel();


    // Selectors

        static autoPtr<BrownianDiffusivityModel> New
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system
        );


    // Member Functions

        //- Dummy write for regIOobject
        bool writeData(Ostream& os) const;

        //- Brownian diffusivity
        virtual tmp<volScalarField> D(const label& sectionI) const = 0;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
