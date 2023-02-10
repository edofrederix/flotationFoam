#ifndef noDetAttach_H
#define noDetAttach_H

#include "deterministicAttachmentModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace deterministicAttachmentModels
{

/*---------------------------------------------------------------------------*\
                           Class noDetAttach Declaration
\*---------------------------------------------------------------------------*/

class noDetAttach
:
    public deterministicAttachmentModel
{
    // Private data


public:

    //- Runtime type information
    TypeName("none");


    // Constructors

        //- Construct from a dictionary and a mesh
        noDetAttach
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system,
            const bool registerObject
        );


    //- Destructor
    virtual ~noDetAttach();


    // Member Functions

        //- Deterministic attachment rate in [m^3/s]
        virtual tmp<volScalarField> rate(const label& sectionI) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace deterministicAttachmentModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
