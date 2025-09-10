#ifndef StokesEinstein_H
#define StokesEinstein_H

#include "particleDiffusivityModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace particleDiffusivityModels
{

/*---------------------------------------------------------------------------*\
                           Class StokesEinstein Declaration
\*---------------------------------------------------------------------------*/

class StokesEinstein
:
    public particleDiffusivityModel
{
    // Private data

        //- Additional multiplication factor, defaults to unity
        scalar f_;

public:

    //- Runtime type information
    TypeName("StokesEinstein");


    // Constructors

        //- Construct from a dictionary and a mesh
        StokesEinstein
        (
            particleModel& model,
            const dictionary& dict
        );


    //- Destructor
    virtual ~StokesEinstein();


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
