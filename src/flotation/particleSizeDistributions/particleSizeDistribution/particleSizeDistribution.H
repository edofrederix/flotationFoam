#ifndef particleSizeDistribution_H
#define particleSizeDistribution_H

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "dictionary.H"
#include "runTimeSelectionTables.H"
#include "fvMesh.H"

namespace Foam
{

/*---------------------------------------------------------------------------*\
                           Class particleSizeDistribution Declaration
\*---------------------------------------------------------------------------*/

class particleSizeDistribution
:
    public regIOobject,
    public PtrList<dimensionedScalar>
{
protected:

    // Protected data

        const fvMesh& mesh_;


public:

    //- Runtime type information
    TypeName("particleSizeDistribution");


    // Declare runtime construction

        declareRunTimeSelectionTable
        (
            autoPtr,
            particleSizeDistribution,
            dictionary,
            (
                const dictionary& dict,
                const fvMesh& mesh,
                const bool registerObject
            ),
            (dict, mesh, registerObject)
        );


    // Static data members


    // Constructors

        // Construct without residual constants
        particleSizeDistribution
        (
            const fvMesh& mesh,
            const bool registerObject
        );

        // Construct with residual constants
        particleSizeDistribution
        (
            const dictionary& dict,
            const fvMesh& mesh,
            const bool registerObject
        );


    //- Destructor
    virtual ~particleSizeDistribution();


    // Selectors

        static autoPtr<particleSizeDistribution> New
        (
            const dictionary& dict,
            const fvMesh& mesh
        );


    // Member Functions

        //- Dummy write for regIOobject
        bool writeData(Ostream& os) const;

        //- Return section name with leading zeros
        word sectionName(const label i) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
