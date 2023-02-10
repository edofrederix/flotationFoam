#ifndef BrownianAttachmentModel_H
#define BrownianAttachmentModel_H

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "dictionary.H"
#include "runTimeSelectionTables.H"
#include "fvMesh.H"
#include "attachmentModel.H"
#include "SherwoodCorrelation.H"

namespace Foam
{

/*---------------------------------------------------------------------------*\
                    Class BrownianAttachmentModel Declaration
\*---------------------------------------------------------------------------*/

class BrownianAttachmentModel
:
    public attachmentModel
{
protected:

    // Protected data

        //- Sherwood correlation
        autoPtr<SherwoodCorrelation> SherwoodCorrel_;

public:

    //- Runtime type information
    TypeName("BrownianAttachmentModel");


    // Declare runtime construction

        declareRunTimeSelectionTable
        (
            autoPtr,
            BrownianAttachmentModel,
            dictionary,
            (
                const dictionary& dict,
                const fvMesh& mesh,
                flotationSystem& system,
                const bool registerObject
            ),
            (dict, mesh, system, registerObject)
        );


    // Static data members


    // Constructors

        BrownianAttachmentModel
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system,
            const bool registerObject
        );


    //- Destructor
    virtual ~BrownianAttachmentModel();


    // Selectors

        static autoPtr<BrownianAttachmentModel> New
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system
        );


    // Member Functions

        //- Brownian attachment rate in [m^3/s]
        virtual tmp<volScalarField> rate
        (
            const label& sectionI
        ) const = 0;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
