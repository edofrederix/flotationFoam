#ifndef SherwoodCorrelation_H
#define SherwoodCorrelation_H

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "dictionary.H"
#include "runTimeSelectionTables.H"
#include "fvMesh.H"

namespace Foam
{

// Forward declarations
class flotationSystem;

/*---------------------------------------------------------------------------*\
                    Class SherwoodCorrelation Declaration
\*---------------------------------------------------------------------------*/

class SherwoodCorrelation
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
    TypeName("SherwoodCorrelation");


    // Declare runtime construction

        declareRunTimeSelectionTable
        (
            autoPtr,
            SherwoodCorrelation,
            dictionary,
            (
                const dictionary& dict,
                const fvMesh& mesh,
                flotationSystem& system
            ),
            (dict, mesh, system)
        );


    // Constructors

        SherwoodCorrelation
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system
        );


    //- Destructor
    virtual ~SherwoodCorrelation();


    // Selectors

        static autoPtr<SherwoodCorrelation> New
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system
        );


    // Member Functions

        //- Sherwood number given the bubble Reynolds number and Schmidt number
        virtual tmp<volScalarField> Sh
        (
            const volScalarField& Re,
            const volScalarField& Sc
        ) const = 0;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
