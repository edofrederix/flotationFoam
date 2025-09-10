#ifndef particleVelocityModel_H
#define particleVelocityModel_H

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "dictionary.H"
#include "runTimeSelectionTables.H"
#include "fvMesh.H"

namespace Foam
{

// Forward declarations
class particleModel;

/*---------------------------------------------------------------------------*\
                    Class particleVelocityModel Declaration
\*---------------------------------------------------------------------------*/

class particleVelocityModel
:
    public regIOobject
{
protected:

    // Protected data

        //- Reference to the FPS object
        particleModel& model_;

        //- Reference to the dictionary
        const dictionary& dict_;


public:

    //- Runtime type information
    TypeName("particleVelocityModel");


    // Declare runtime construction

        declareRunTimeSelectionTable
        (
            autoPtr,
            particleVelocityModel,
            dictionary,
            (
                particleModel& model,
                const dictionary& dict
            ),
            (model, dict)
        );


    // Static data members


    // Constructors

        particleVelocityModel
        (
            particleModel& model,
            const dictionary& dict
        );


    //- Destructor
    virtual ~particleVelocityModel();


    // Selectors

        static autoPtr<particleVelocityModel> New
        (
            particleModel& model,
            const dictionary& dict
        );


    // Member Functions

        //- Dummy write for regIOobject
        bool writeData(Ostream& os) const;

        //- Correct the particle velocities
        virtual void correct() = 0;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
