#ifndef spherical_H
#define spherical_H

#include "deterministicAttachmentModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace deterministicAttachmentModels
{

/*---------------------------------------------------------------------------*\
                           Class spherical Declaration
\*---------------------------------------------------------------------------*/

class spherical
:
    public deterministicAttachmentModel
{
    // Private data


public:

    //- Runtime type information
    TypeName("spherical");


    // Constructors

        //- Construct from a dictionary and a mesh
        spherical
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system,
            const bool registerObject
        );


    //- Destructor
    virtual ~spherical();


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
