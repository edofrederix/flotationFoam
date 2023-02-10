#ifndef idealCollision_H
#define idealCollision_H

#include "collisionEfficiencyModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace collisionEfficiencyModels
{

/*---------------------------------------------------------------------------*\
                           Class idealCollision Declaration
\*---------------------------------------------------------------------------*/

class idealCollision
:
    public collisionEfficiencyModel
{
    // Private data


public:

    //- Runtime type information
    TypeName("ideal");


    // Constructors

        //- Construct from a dictionary and a mesh
        idealCollision
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system,
            const bool registerObject
        );


    //- Destructor
    virtual ~idealCollision();


    // Member Functions

        virtual tmp<volScalarField> efficiency(const label& sectionI) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace collisionEfficiencyModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
