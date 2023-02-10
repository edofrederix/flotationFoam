#ifndef constantInductionTime_H
#define constantInductionTime_H

#include "inductionTimeModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace inductionTimeModels
{

/*---------------------------------------------------------------------------*\
                           Class constantInductionTime Declaration
\*---------------------------------------------------------------------------*/

class constantInductionTime
:
    public inductionTimeModel
{
    // Private data

        //- Constant induction time value
        scalar t_;

public:

    //- Runtime type information
    TypeName("constant");


    // Constructors

        //- Construct from a dictionary and a mesh
        constantInductionTime
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system,
            const bool registerObject
        );


    //- Destructor
    virtual ~constantInductionTime();


    // Member Functions

        virtual scalar t(const label& sectionI) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace inductionTimeModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
