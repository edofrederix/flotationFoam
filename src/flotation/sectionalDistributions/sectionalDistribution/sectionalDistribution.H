#ifndef sectionalDistribution_H
#define sectionalDistribution_H

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "dictionary.H"
#include "runTimeSelectionTables.H"
#include "fvMesh.H"

namespace Foam
{

/*---------------------------------------------------------------------------*\
                           Class sectionalDistribution Declaration
\*---------------------------------------------------------------------------*/

class sectionalDistribution
:
    public regIOobject,
    public PtrList<dimensionedScalar>
{
protected:

    // Protected data

        const fvMesh& mesh_;


public:

    //- Runtime type information
    TypeName("sectionalDistribution");


    // Declare runtime construction

        declareRunTimeSelectionTable
        (
            autoPtr,
            sectionalDistribution,
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
        sectionalDistribution
        (
            const fvMesh& mesh,
            const bool registerObject
        );

        // Construct with residual constants
        sectionalDistribution
        (
            const dictionary& dict,
            const fvMesh& mesh,
            const bool registerObject
        );


    //- Destructor
    virtual ~sectionalDistribution();


    // Selectors

        static autoPtr<sectionalDistribution> New
        (
            const dictionary& dict,
            const fvMesh& mesh
        );


    // Member Functions

        //- Dummy write for regIOobject
        bool writeData(Ostream& os) const;

        //- Return section name with leading zeros
        word sectionName(const label sectionI) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
