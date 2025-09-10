#ifndef Sh_H
#define Sh_H

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "dictionary.H"
#include "runTimeSelectionTables.H"
#include "fvMesh.H"

namespace Foam
{

/*---------------------------------------------------------------------------*\
                        Class SherwoodNumber Declaration
\*---------------------------------------------------------------------------*/

class SherwoodNumber
{
protected:

    // Protected data

        //- Reference to the mesh
        const fvMesh& mesh_;

public:

    //- Runtime type information
    TypeName("SherwoodNumber");


    // Declare runtime construction

        declareRunTimeSelectionTable
        (
            autoPtr,
            SherwoodNumber,
            dictionary,
            (
                const fvMesh& mesh,
                const word type
            ),
            (mesh, type)
        );


    // Constructors

        SherwoodNumber
        (
            const fvMesh& mesh,
            const word type
        );


    //- Destructor
    virtual ~SherwoodNumber();


    // Selectors

        static autoPtr<SherwoodNumber> New
        (
            const fvMesh& mesh,
            const word type
        );


    // Member Functions

        //- SherwoodNumber number given the bubble Reynolds number and Schmidt number
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
