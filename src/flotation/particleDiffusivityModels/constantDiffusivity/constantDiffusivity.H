#ifndef constantDiffusivity_H
#define constantDiffusivity_H

#include "particleDiffusivityModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace particleDiffusivityModels
{

/*---------------------------------------------------------------------------*\
                           Class constantDiffusivity Declaration
\*---------------------------------------------------------------------------*/

class constantDiffusivity
:
    public particleDiffusivityModel
{
    // Private data

        // Diffusivity value
        dimensionedScalar D_;


public:

    //- Runtime type information
    TypeName("constant");


    // Constructors

        //- Construct from a dictionary and a mesh
        constantDiffusivity
        (
            particleModel& model,
            const dictionary& dict
        );


    //- Destructor
    virtual ~constantDiffusivity();


    // Member Functions

        //- Correct the particle diffusivity
        virtual void correct();
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace particleDiffusivityModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
