#ifndef attachmentModel_H
#define attachmentModel_H

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "dictionary.H"
#include "fvMesh.H"
#include "interactionModel.H"

namespace Foam
{

/*---------------------------------------------------------------------------*\
                    Class attachmentModel Declaration
\*---------------------------------------------------------------------------*/

class attachmentModel
:
    public interactionModel
{
protected:

    // Protected data


public:

    //- Runtime type information
    TypeName("attachmentModel");


    // Constructors

        attachmentModel
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system,
            const bool registerObject,
            const word subTypeName
        );


    //- Destructor
    virtual ~attachmentModel();

    // Member Functions

        //- Create empty efficiency field
        tmp<volScalarField> emptyRateField(const word& fieldName) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
