#ifndef detachmentModel_H
#define detachmentModel_H

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "dictionary.H"
#include "fvMesh.H"
#include "interactionModel.H"

namespace Foam
{

/*---------------------------------------------------------------------------*\
                    Class detachmentModel Declaration
\*---------------------------------------------------------------------------*/

class detachmentModel
:
    public interactionModel
{
protected:

    // Protected data


public:

    //- Runtime type information
    TypeName("detachmentModel");


    // Constructors

        detachmentModel
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system,
            const bool registerObject,
            const word subTypeName
        );


    //- Destructor
    virtual ~detachmentModel();

    // Member Functions

        //- Create empty efficiency field
        tmp<volScalarField> emptyRateField(const word& fieldName) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
