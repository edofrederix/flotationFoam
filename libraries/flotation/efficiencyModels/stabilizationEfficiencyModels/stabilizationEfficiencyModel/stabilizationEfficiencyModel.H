#ifndef stabilizationEfficiencyModel_H
#define stabilizationEfficiencyModel_H

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "dictionary.H"
#include "runTimeSelectionTables.H"
#include "fvMesh.H"
#include "efficiencyModel.H"

namespace Foam
{

/*---------------------------------------------------------------------------*\
                    Class stabilizationEfficiencyModel Declaration
\*---------------------------------------------------------------------------*/

class stabilizationEfficiencyModel
:
    public efficiencyModel
{
protected:

    // Protected data


public:

    //- Runtime type information
    TypeName("stabilizationEfficiencyModel");


    // Declare runtime construction

        declareRunTimeSelectionTable
        (
            autoPtr,
            stabilizationEfficiencyModel,
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

        stabilizationEfficiencyModel
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system,
            const bool registerObject
        );


    //- Destructor
    virtual ~stabilizationEfficiencyModel();


    // Selectors

        static autoPtr<stabilizationEfficiencyModel> New
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
