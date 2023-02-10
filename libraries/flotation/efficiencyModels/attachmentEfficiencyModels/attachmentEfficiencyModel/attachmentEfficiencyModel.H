#ifndef attachmentEfficiencyModel_H
#define attachmentEfficiencyModel_H

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "dictionary.H"
#include "runTimeSelectionTables.H"
#include "fvMesh.H"
#include "efficiencyModel.H"
#include "inductionTimeModel.H"

namespace Foam
{

/*---------------------------------------------------------------------------*\
                    Class attachmentEfficiencyModel Declaration
\*---------------------------------------------------------------------------*/

class attachmentEfficiencyModel
:
    public efficiencyModel
{
protected:

    // Protected data

        //- Induction time model
        autoPtr<inductionTimeModel> induction_;

public:

    //- Runtime type information
    TypeName("attachmentEfficiencyModel");


    // Declare runtime construction

        declareRunTimeSelectionTable
        (
            autoPtr,
            attachmentEfficiencyModel,
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

        attachmentEfficiencyModel
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system,
            const bool registerObject
        );


    //- Destructor
    virtual ~attachmentEfficiencyModel();


    // Selectors

        static autoPtr<attachmentEfficiencyModel> New
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system
        );


    // Member Functions

        virtual tmp<volScalarField> efficiency
        (
            const label& sectionI
        ) const = 0;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
