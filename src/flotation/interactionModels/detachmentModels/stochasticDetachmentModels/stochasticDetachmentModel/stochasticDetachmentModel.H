#ifndef stochasticDetachmentModel_H
#define stochasticDetachmentModel_H

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "dictionary.H"
#include "runTimeSelectionTables.H"
#include "fvMesh.H"
#include "detachmentModel.H"

namespace Foam
{

/*---------------------------------------------------------------------------*\
                    Class stochasticDetachmentModel Declaration
\*---------------------------------------------------------------------------*/

class stochasticDetachmentModel
:
    public detachmentModel
{
protected:

    // Protected data


public:

    //- Runtime type information
    TypeName("stochasticDetachmentModel");


    // Declare runtime construction

        declareRunTimeSelectionTable
        (
            autoPtr,
            stochasticDetachmentModel,
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

        stochasticDetachmentModel
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system,
            const bool registerObject
        );


    //- Destructor
    virtual ~stochasticDetachmentModel();


    // Selectors

        static autoPtr<stochasticDetachmentModel> New
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system
        );


    // Member Functions

        //- Stochastic detachment rate in [m^3/s]
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
