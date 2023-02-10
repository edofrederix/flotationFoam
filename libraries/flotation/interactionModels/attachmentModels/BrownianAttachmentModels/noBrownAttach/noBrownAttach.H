#ifndef noBrownAttach_H
#define noBrownAttach_H

#include "BrownianAttachmentModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace BrownianAttachmentModels
{

/*---------------------------------------------------------------------------*\
                         Class noBrownAttach Declaration
\*---------------------------------------------------------------------------*/

class noBrownAttach
:
    public BrownianAttachmentModel
{
    // Private data


public:

    //- Runtime type information
    TypeName("none");


    // Constructors

        //- Construct from a dictionary and a mesh
        noBrownAttach
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system,
            const bool registerObject
        );


    //- Destructor
    virtual ~noBrownAttach();


    // Member Functions

        //- Brownian attachment rate in [m^3/s]
        virtual tmp<volScalarField> rate(const label& sectionI) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace BrownianAttachmentModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
