#ifndef Dai_H
#define Dai_H

#include "inductionTimeModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace inductionTimeModels
{

/*---------------------------------------------------------------------------*\
                           Class Dai Declaration
\*---------------------------------------------------------------------------*/

class Dai
:
    public inductionTimeModel
{
    // Private data

        //- Model coefficients
        scalar A_;
        scalar B_;

public:

    //- Runtime type information
    TypeName("Dai");


    // Constructors

        //- Construct from a dictionary and a mesh
        Dai
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system,
            const bool registerObject
        );


    //- Destructor
    virtual ~Dai();


    // Member Functions

        virtual scalar t(const label& sectionI) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace inductionTimeModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
