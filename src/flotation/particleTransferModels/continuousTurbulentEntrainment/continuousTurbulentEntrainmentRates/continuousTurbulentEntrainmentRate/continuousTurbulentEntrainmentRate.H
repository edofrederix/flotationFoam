#ifndef continuousTurbulentEntrainmentRate_H
#define continuousTurbulentEntrainmentRate_H

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "dictionary.H"
#include "runTimeSelectionTables.H"
#include "volFields.H"

namespace Foam
{
namespace particleTransferModels
{

class continuousTurbulentEntrainment;

/*---------------------------------------------------------------------------*\
                    Class continuousTurbulentEntrainmentRate Declaration
\*---------------------------------------------------------------------------*/

class continuousTurbulentEntrainmentRate
{
protected:

    // Protected Data

        //- Reference to the continuous entrainment particle transfer model
        continuousTurbulentEntrainment& transfer_;

public:

    //- Runtime type information
    TypeName("continuousTurbulentEntrainmentRate");

    // Declare runtime construction

        declareRunTimeSelectionTable
        (
            autoPtr,
            continuousTurbulentEntrainmentRate,
            dictionary,
            (
                continuousTurbulentEntrainment& transfer,
                const dictionary& dict
            ),
            (transfer, dict)
        );

    // Constructors

        continuousTurbulentEntrainmentRate
        (
            continuousTurbulentEntrainment& transfer,
            const dictionary& dict
        );

    // Selectors

        static autoPtr<continuousTurbulentEntrainmentRate> New
        (
            continuousTurbulentEntrainment& transfer,
            const dictionary& dict
        );


    //- Destructor
    virtual ~continuousTurbulentEntrainmentRate();

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
