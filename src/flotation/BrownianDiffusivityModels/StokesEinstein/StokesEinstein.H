#ifndef StokesEinstein_H
#define StokesEinstein_H

#include "BrownianDiffusivityModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace BrownianDiffusivityModels
{

/*---------------------------------------------------------------------------*\
                           Class StokesEinstein Declaration
\*---------------------------------------------------------------------------*/

class StokesEinstein
:
    public BrownianDiffusivityModel
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
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system,
            const bool registerObject
        );


    //- Destructor
    virtual ~StokesEinstein();


    // Member Functions

        //- Brownian diffusivity
        tmp<volScalarField> D(const label& sectionI) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace BrownianDiffusivityModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
