#ifndef YoonLuttrellStokesCollision_H
#define YoonLuttrellStokesCollision_H

#include "collisionEfficiencyModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace collisionEfficiencyModels
{

/*---------------------------------------------------------------------------*\
                           Class YoonLuttrellStokesCollision Declaration
\*---------------------------------------------------------------------------*/

class YoonLuttrellStokesCollision
:
    public collisionEfficiencyModel
{
    // Private data


public:

    //- Runtime type information
    TypeName("YoonLuttrellStokes");


    // Constructors

        //- Construct from a dictionary and a mesh
        YoonLuttrellStokesCollision
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system,
            const bool registerObject
        );


    //- Destructor
    virtual ~YoonLuttrellStokesCollision();


    // Member Functions

        virtual tmp<volScalarField> efficiency(const label& sectionI) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace collisionEfficiencyModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
