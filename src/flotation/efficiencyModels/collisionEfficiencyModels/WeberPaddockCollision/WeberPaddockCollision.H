#ifndef WeberPaddockCollision_H
#define WeberPaddockCollision_H

#include "collisionEfficiencyModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace collisionEfficiencyModels
{

/*---------------------------------------------------------------------------*\
                           Class WeberPaddockCollision Declaration
\*---------------------------------------------------------------------------*/

class WeberPaddockCollision
:
    public collisionEfficiencyModel
{
    // Private data


public:

    //- Runtime type information
    TypeName("WeberPaddock");


    // Constructors

        //- Construct from a dictionary and a mesh
        WeberPaddockCollision
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system,
            const bool registerObject
        );


    //- Destructor
    virtual ~WeberPaddockCollision();


    // Member Functions

        virtual tmp<volScalarField> efficiency(const label& sectionI) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace collisionEfficiencyModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
