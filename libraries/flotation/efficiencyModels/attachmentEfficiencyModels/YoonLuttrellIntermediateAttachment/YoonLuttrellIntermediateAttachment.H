#ifndef YoonLuttrellIntermediateAttachment_H
#define YoonLuttrellIntermediateAttachment_H

#include "attachmentEfficiencyModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace attachmentEfficiencyModels
{

/*---------------------------------------------------------------------------*\
                           Class YoonLuttrellIntermediateAttachment Declaration
\*---------------------------------------------------------------------------*/

class YoonLuttrellIntermediateAttachment
:
    public attachmentEfficiencyModel
{
    // Private data


public:

    //- Runtime type information
    TypeName("YoonLuttrellIntermediate");


    // Constructors

        //- Construct from a dictionary and a mesh
        YoonLuttrellIntermediateAttachment
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system,
            const bool registerObject
        );


    //- Destructor
    virtual ~YoonLuttrellIntermediateAttachment();


    // Member Functions

        virtual tmp<volScalarField> efficiency(const label& sectionI) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace attachmentEfficiencyModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
