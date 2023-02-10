#ifndef stochasticAttachmentModel_H
#define stochasticAttachmentModel_H

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "dictionary.H"
#include "runTimeSelectionTables.H"
#include "fvMesh.H"
#include "attachmentModel.H"

namespace Foam
{

/*---------------------------------------------------------------------------*\
                    Class stochasticAttachmentModel Declaration
\*---------------------------------------------------------------------------*/

class stochasticAttachmentModel
:
    public attachmentModel
{
protected:

    // Protected data


public:

    //- Runtime type information
    TypeName("stochasticAttachmentModel");


    // Declare runtime construction

        declareRunTimeSelectionTable
        (
            autoPtr,
            stochasticAttachmentModel,
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

        stochasticAttachmentModel
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system,
            const bool registerObject
        );


    //- Destructor
    virtual ~stochasticAttachmentModel();


    // Selectors

        static autoPtr<stochasticAttachmentModel> New
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system
        );


    // Member Functions

        //- Stochastic attachment rate in [m^3/s]
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
