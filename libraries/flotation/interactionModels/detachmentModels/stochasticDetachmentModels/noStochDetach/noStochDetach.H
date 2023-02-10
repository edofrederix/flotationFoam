#ifndef noStochDetach_H
#define noStochDetach_H

#include "stochasticDetachmentModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace stochasticDetachmentModels
{

/*---------------------------------------------------------------------------*\
                           Class noStochDetach Declaration
\*---------------------------------------------------------------------------*/

class noStochDetach
:
    public stochasticDetachmentModel
{
    // Private data


public:

    //- Runtime type information
    TypeName("none");


    // Constructors

        //- Construct from a dictionary and a mesh
        noStochDetach
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system,
            const bool registerObject
        );


    //- Destructor
    virtual ~noStochDetach();


    // Member Functions

        //- Stochastic detachment rate in [m^3/s]
        virtual tmp<volScalarField> rate(const label& sectionI) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace stochasticDetachmentModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
