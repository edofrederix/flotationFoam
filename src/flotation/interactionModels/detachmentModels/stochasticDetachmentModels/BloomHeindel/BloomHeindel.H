#ifndef BloomHeindel_H
#define BloomHeindel_H

#include "stochasticDetachmentModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace stochasticDetachmentModels
{

/*---------------------------------------------------------------------------*\
                           Class BloomHeindel Declaration
\*---------------------------------------------------------------------------*/

class BloomHeindel
:
    public stochasticDetachmentModel
{
    // Private data


public:

    //- Runtime type information
    TypeName("BloomHeindel");


    // Constructors

        //- Construct from a dictionary and a mesh
        BloomHeindel
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system,
            const bool registerObject
        );


    //- Destructor
    virtual ~BloomHeindel();


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
