#ifndef noInductionTime_H
#define noInductionTime_H

#include "inductionTimeModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace inductionTimeModels
{

/*---------------------------------------------------------------------------*\
                           Class noInductionTime Declaration
\*---------------------------------------------------------------------------*/

class noInductionTime
:
    public inductionTimeModel
{
public:

    //- Runtime type information
    TypeName("none");


    // Constructors

        //- Construct from a dictionary and a mesh
        noInductionTime
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system,
            const bool registerObject
        );


    //- Destructor
    virtual ~noInductionTime();


    // Member Functions

        virtual scalar t(const label& sectionI) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace inductionTimeModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
