#ifndef idealStabilization_H
#define idealStabilization_H

#include "stabilizationEfficiencyModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace stabilizationEfficiencyModels
{

/*---------------------------------------------------------------------------*\
                           Class idealStabilization Declaration
\*---------------------------------------------------------------------------*/

class idealStabilization
:
    public stabilizationEfficiencyModel
{
    // Private data


public:

    //- Runtime type information
    TypeName("ideal");


    // Constructors

        //- Construct from a dictionary and a mesh
        idealStabilization
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system,
            const bool registerObject
        );


    //- Destructor
    virtual ~idealStabilization();


    // Member Functions

        virtual tmp<volScalarField> efficiency(const label& sectionI) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace stabilizationEfficiencyModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
