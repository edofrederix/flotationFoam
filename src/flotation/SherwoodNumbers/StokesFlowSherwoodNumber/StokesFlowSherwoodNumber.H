#ifndef StokesFlowSh_H
#define StokesFlowSh_H

#include "SherwoodNumber.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace SherwoodNumbers
{

/*---------------------------------------------------------------------------*\
                    Class StokesFlowSherwoodNumber Declaration
\*---------------------------------------------------------------------------*/

class StokesFlowSherwoodNumber
:
    public SherwoodNumber
{
public:

    //- Runtime type information
    TypeName("StokesFlow");


    // Constructors

        //- Construct from mesh and type
        StokesFlowSherwoodNumber
        (
            const fvMesh& mesh,
            const word type
        );


    //- Destructor
    virtual ~StokesFlowSherwoodNumber();


    // Member Functions

        //- SherwoodNumber number given the bubble Peclet and Reynolds number
        virtual tmp<volScalarField> Sh
        (
            const volScalarField& Pe,
            const volScalarField& Re
        ) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace SherwoodNumbers
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
