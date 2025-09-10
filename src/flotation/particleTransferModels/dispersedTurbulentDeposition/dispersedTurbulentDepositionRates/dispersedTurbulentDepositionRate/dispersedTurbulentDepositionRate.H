#ifndef dispersedTurbulentDepositionRate_H
#define dispersedTurbulentDepositionRate_H

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "dictionary.H"
#include "runTimeSelectionTables.H"
#include "volFields.H"

namespace Foam
{
namespace particleTransferModels
{

class dispersedTurbulentDeposition;

/*---------------------------------------------------------------------------*\
                    Class dispersedTurbulentDepositionRate Declaration
\*---------------------------------------------------------------------------*/

class dispersedTurbulentDepositionRate
{
protected:

    // Protected Data

        //- Reference to the dispersed deposition particle transfer model
        dispersedTurbulentDeposition& transfer_;

public:

    //- Runtime type information
    TypeName("dispersedTurbulentDepositionRate");

    // Declare runtime construction

        declareRunTimeSelectionTable
        (
            autoPtr,
            dispersedTurbulentDepositionRate,
            dictionary,
            (
                dispersedTurbulentDeposition& transfer,
                const dictionary& dict
            ),
            (transfer, dict)
        );

    // Constructors

        dispersedTurbulentDepositionRate
        (
            dispersedTurbulentDeposition& transfer,
            const dictionary& dict
        );

    // Selectors

        static autoPtr<dispersedTurbulentDepositionRate> New
        (
            dispersedTurbulentDeposition& transfer,
            const dictionary& dict
        );


    //- Destructor
    virtual ~dispersedTurbulentDepositionRate();

    // Member Functions

        //- Deposition rate for given section in [m^3/s]
        virtual tmp<volScalarField> R(const volScalarField& N) const = 0;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace particleTransferModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
