#ifndef SutherlandAttachment_H
#define SutherlandAttachment_H

#include "attachmentEfficiencyModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace attachmentEfficiencyModels
{

/*---------------------------------------------------------------------------*\
                           Class SutherlandAttachment Declaration
\*---------------------------------------------------------------------------*/

class SutherlandAttachment
:
    public attachmentEfficiencyModel
{
    // Private data


public:

    //- Runtime type information
    TypeName("Sutherland");


    // Constructors

        //- Construct from a dictionary and a mesh
        SutherlandAttachment
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system,
            const bool registerObject
        );


    //- Destructor
    virtual ~SutherlandAttachment();


    // Member Functions

        virtual tmp<volScalarField> efficiency(const label& sectionI) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace attachmentEfficiencyModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
