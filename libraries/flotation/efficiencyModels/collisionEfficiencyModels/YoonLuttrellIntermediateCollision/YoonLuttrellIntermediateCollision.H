#ifndef YoonLuttrellIntermediateCollision_H
#define YoonLuttrellIntermediateCollision_H

#include "collisionEfficiencyModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace collisionEfficiencyModels
{

/*---------------------------------------------------------------------------*\
                           Class YoonLuttrellIntermediateCollision Declaration
\*---------------------------------------------------------------------------*/

class YoonLuttrellIntermediateCollision
:
    public collisionEfficiencyModel
{
    // Private data


public:

    //- Runtime type information
    TypeName("YoonLuttrellIntermediate");


    // Constructors

        //- Construct from a dictionary and a mesh
        YoonLuttrellIntermediateCollision
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system,
            const bool registerObject
        );


    //- Destructor
    virtual ~YoonLuttrellIntermediateCollision();


    // Member Functions

        virtual tmp<volScalarField> efficiency(const label& sectionI) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace collisionEfficiencyModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
