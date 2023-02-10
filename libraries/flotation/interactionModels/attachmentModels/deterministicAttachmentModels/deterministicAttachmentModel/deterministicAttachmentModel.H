#ifndef deterministicAttachmentModel_H
#define deterministicAttachmentModel_H

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "dictionary.H"
#include "runTimeSelectionTables.H"
#include "fvMesh.H"
#include "attachmentModel.H"

namespace Foam
{

/*---------------------------------------------------------------------------*\
                    Class deterministicAttachmentModel Declaration
\*---------------------------------------------------------------------------*/

class deterministicAttachmentModel
:
    public attachmentModel
{
protected:

    // Protected data


public:

    //- Runtime type information
    TypeName("deterministicAttachmentModel");


    // Declare runtime construction

        declareRunTimeSelectionTable
        (
            autoPtr,
            deterministicAttachmentModel,
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

        deterministicAttachmentModel
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system,
            const bool registerObject
        );


    //- Destructor
    virtual ~deterministicAttachmentModel();


    // Selectors

        static autoPtr<deterministicAttachmentModel> New
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system
        );


    // Member Functions

        //- Deterministic attachment rate in [m^3/s]
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
