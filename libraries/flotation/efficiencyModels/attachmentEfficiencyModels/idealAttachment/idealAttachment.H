#ifndef idealAttachment_H
#define idealAttachment_H

#include "attachmentEfficiencyModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace attachmentEfficiencyModels
{

/*---------------------------------------------------------------------------*\
                           Class idealAttachment Declaration
\*---------------------------------------------------------------------------*/

class idealAttachment
:
    public attachmentEfficiencyModel
{
    // Private data


public:

    //- Runtime type information
    TypeName("ideal");


    // Constructors

        //- Construct from a dictionary and a mesh
        idealAttachment
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system,
            const bool registerObject
        );


    //- Destructor
    virtual ~idealAttachment();


    // Member Functions

        virtual tmp<volScalarField> efficiency(const label& sectionI) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace attachmentEfficiencyModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
