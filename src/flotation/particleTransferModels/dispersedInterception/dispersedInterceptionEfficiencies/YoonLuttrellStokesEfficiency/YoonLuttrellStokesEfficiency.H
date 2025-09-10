#ifndef YoonLuttrellStokesEfficiency_H
#define YoonLuttrellStokesEfficiency_H

#include "dispersedInterceptionEfficiency.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace particleTransferModels
{

namespace dispersedInterceptionEfficiencies
{

/*---------------------------------------------------------------------------*\
                  Class YoonLuttrellStokesEfficiency Declaration
\*---------------------------------------------------------------------------*/

class YoonLuttrellStokesEfficiency
:
    public dispersedInterceptionEfficiency
{
public:

    //- Runtime type information
    TypeName("YoonLuttrellStokes");


    // Constructors

        //- Construct from a dictionary and a mesh
        YoonLuttrellStokesEfficiency
        (
            dispersedInterception& transfer,
            const dictionary& dict
        );


    //- Destructor
    virtual ~YoonLuttrellStokesEfficiency();


    // Member Functions

        // Efficiency
        virtual tmp<volScalarField> E(const volScalarField& N) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace dispersedInterceptionEfficiencies
} // End namespace particleTransferModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
