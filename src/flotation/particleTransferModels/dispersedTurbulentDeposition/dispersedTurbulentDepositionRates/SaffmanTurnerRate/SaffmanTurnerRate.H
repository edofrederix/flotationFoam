#ifndef SaffmanTurnerRate_H
#define SaffmanTurnerRate_H

#include "dispersedTurbulentDepositionRate.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace particleTransferModels
{

namespace dispersedTurbulentDepositionRates
{

/*---------------------------------------------------------------------------*\
                        Class SaffmanTurnerRate Declaration
\*---------------------------------------------------------------------------*/

class SaffmanTurnerRate
:
    public dispersedTurbulentDepositionRate
{
public:

    //- Runtime type information
    TypeName("SaffmanTurner");


    // Constructors

        //- Construct from a dictionary and a mesh
        SaffmanTurnerRate
        (
            dispersedTurbulentDeposition& transfer,
            const dictionary& dict
        );


    //- Destructor
    virtual ~SaffmanTurnerRate();


    // Member Functions

        //- Deposition rate for given section in [m^3/s]
        virtual tmp<volScalarField> R(const volScalarField& N) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace dispersedTurbulentDepositionRates
} // End namespace particleTransferModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
