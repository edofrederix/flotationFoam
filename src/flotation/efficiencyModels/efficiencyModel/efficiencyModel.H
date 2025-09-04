#ifndef efficiencyModel_H
#define efficiencyModel_H

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "dictionary.H"
#include "fvMesh.H"

namespace Foam
{

// Forward declarations
class flotationSystem;

/*---------------------------------------------------------------------------*\
                    Class efficiencyModel Declaration
\*---------------------------------------------------------------------------*/

class efficiencyModel
:
    public regIOobject
{
protected:

    // Protected data

        //- Reference to the mesh
        const fvMesh& mesh_;

        //- Reference to the FPS object
        flotationSystem& system_;

        //- Reference to the dictionary
        const dictionary& dict_;


public:

    //- Runtime type information
    TypeName("efficiencyModel");


    // Constructors

        efficiencyModel
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system,
            const bool registerObject,
            const word subTypeName
        );


    //- Destructor
    virtual ~efficiencyModel();

    // Member Functions

        //- Create empty efficiency field
        tmp<volScalarField> emptyEfficiencyField(const word& fieldName) const;

        //- Dummy write for regIOobject
        bool writeData(Ostream& os) const;

        //- Clip an efficiency field
        tmp<volScalarField> clip(const tmp<volScalarField> P) const;

        //- Particle-bubble diameter ratio
        tmp<volScalarField> R(const label sectionI) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
