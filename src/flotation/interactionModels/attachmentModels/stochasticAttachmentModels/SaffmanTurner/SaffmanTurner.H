#ifndef SaffmanTurner_H
#define SaffmanTurner_H

#include "stochasticAttachmentModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace stochasticAttachmentModels
{

/*---------------------------------------------------------------------------*\
                           Class SaffmanTurner Declaration
\*---------------------------------------------------------------------------*/

class SaffmanTurner
:
    public stochasticAttachmentModel
{
    // Private data


public:

    //- Runtime type information
    TypeName("SaffmanTurner");


    // Constructors

        //- Construct from a dictionary and a mesh
        SaffmanTurner
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system,
            const bool registerObject
        );


    //- Destructor
    virtual ~SaffmanTurner();


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
