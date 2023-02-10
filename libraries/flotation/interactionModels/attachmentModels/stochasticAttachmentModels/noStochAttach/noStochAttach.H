#ifndef noStochAttach_H
#define noStochAttach_H

#include "stochasticAttachmentModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace stochasticAttachmentModels
{

/*---------------------------------------------------------------------------*\
                           Class noStochAttach Declaration
\*---------------------------------------------------------------------------*/

class noStochAttach
:
    public stochasticAttachmentModel
{
    // Private data


public:

    //- Runtime type information
    TypeName("none");


    // Constructors

        //- Construct from a dictionary and a mesh
        noStochAttach
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system,
            const bool registerObject
        );


    //- Destructor
    virtual ~noStochAttach();


    // Member Functions

        //- Stochastic attachment rate in [m^3/s]
        virtual tmp<volScalarField> rate(const label& sectionI) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace stochasticAttachmentModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
