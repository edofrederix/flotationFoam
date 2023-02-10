#ifndef noBrownDiff_H
#define noBrownDiff_H

#include "BrownianDiffusivityModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace BrownianDiffusivityModels
{

/*---------------------------------------------------------------------------*\
                           Class noBrownDiff Declaration
\*---------------------------------------------------------------------------*/

class noBrownDiff
:
    public BrownianDiffusivityModel
{
    // Private data


public:

    //- Runtime type information
    TypeName("none");


    // Constructors

        //- Construct from a dictionary and a mesh
        noBrownDiff
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system,
            const bool registerObject
        );


    //- Destructor
    virtual ~noBrownDiff();


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
