#ifndef collisionEfficiencyModel_H
#define collisionEfficiencyModel_H

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "dictionary.H"
#include "runTimeSelectionTables.H"
#include "fvMesh.H"
#include "efficiencyModel.H"

namespace Foam
{

/*---------------------------------------------------------------------------*\
                    Class collisionEfficiencyModel Declaration
\*---------------------------------------------------------------------------*/

class collisionEfficiencyModel
:
    public efficiencyModel
{
protected:

    // Protected data


public:

    //- Runtime type information
    TypeName("collisionEfficiencyModel");


    // Declare runtime construction

        declareRunTimeSelectionTable
        (
            autoPtr,
            collisionEfficiencyModel,
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

        collisionEfficiencyModel
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system,
            const bool registerObject
        );


    //- Destructor
    virtual ~collisionEfficiencyModel();


    // Selectors

        static autoPtr<collisionEfficiencyModel> New
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
