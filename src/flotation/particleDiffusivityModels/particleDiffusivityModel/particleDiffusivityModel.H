#ifndef particleDiffusivityModel_H
#define particleDiffusivityModel_H

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "dictionary.H"
#include "runTimeSelectionTables.H"
#include "fvMesh.H"

namespace Foam
{

// Forward declarations
class particleModel;

/*---------------------------------------------------------------------------*\
                    Class particleDiffusivityModel Declaration
\*---------------------------------------------------------------------------*/

class particleDiffusivityModel
:
    public regIOobject
{
protected:

    // Protected data

        //- Reference to the particle model
        particleModel& model_;

        //- Reference to the dictionary
        const dictionary& dict_;


public:

    //- Runtime type information
    TypeName("particleDiffusivityModel");


    // Declare runtime construction

        declareRunTimeSelectionTable
        (
            autoPtr,
            particleDiffusivityModel,
            dictionary,
            (
                particleModel& model,
                const dictionary& dict
            ),
            (model, dict)
        );


    // Static data members


    // Constructors

        particleDiffusivityModel
        (
            particleModel& model,
            const dictionary& dict
        );


    //- Destructor
    virtual ~particleDiffusivityModel();


    // Selectors

        static autoPtr<particleDiffusivityModel> New
        (
            particleModel& model,
            const dictionary& dict
        );


    // Member Functions

        //- Dummy write for regIOobject
        bool writeData(Ostream& os) const;

        //- Correct the particle diffusivity
        virtual void correct() = 0;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
