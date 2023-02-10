#ifndef SutherlandCollision_H
#define SutherlandCollision_H

#include "collisionEfficiencyModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace collisionEfficiencyModels
{

/*---------------------------------------------------------------------------*\
                           Class SutherlandCollision Declaration
\*---------------------------------------------------------------------------*/

class SutherlandCollision
:
    public collisionEfficiencyModel
{
    // Private data


public:

    //- Runtime type information
    TypeName("Sutherland");


    // Constructors

        //- Construct from a dictionary and a mesh
        SutherlandCollision
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system,
            const bool registerObject
        );


    //- Destructor
    virtual ~SutherlandCollision();


    // Member Functions

        virtual tmp<volScalarField> efficiency(const label& sectionI) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace collisionEfficiencyModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
