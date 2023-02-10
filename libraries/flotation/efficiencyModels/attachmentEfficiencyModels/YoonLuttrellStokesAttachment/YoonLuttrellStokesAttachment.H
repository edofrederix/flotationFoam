#ifndef YoonLuttrellStokesAttachment_H
#define YoonLuttrellStokesAttachment_H

#include "attachmentEfficiencyModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace attachmentEfficiencyModels
{

/*---------------------------------------------------------------------------*\
                           Class YoonLuttrellStokesAttachment Declaration
\*---------------------------------------------------------------------------*/

class YoonLuttrellStokesAttachment
:
    public attachmentEfficiencyModel
{
    // Private data


public:

    //- Runtime type information
    TypeName("YoonLuttrellStokes");


    // Constructors

        //- Construct from a dictionary and a mesh
        YoonLuttrellStokesAttachment
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system,
            const bool registerObject
        );


    //- Destructor
    virtual ~YoonLuttrellStokesAttachment();


    // Member Functions

        virtual tmp<volScalarField> efficiency(const label& sectionI) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace attachmentEfficiencyModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
