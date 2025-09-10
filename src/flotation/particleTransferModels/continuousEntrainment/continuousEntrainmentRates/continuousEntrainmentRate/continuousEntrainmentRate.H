#ifndef continuousEntrainmentRate_H
#define continuousEntrainmentRate_H

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "dictionary.H"
#include "runTimeSelectionTables.H"
#include "volFields.H"

namespace Foam
{
namespace particleTransferModels
{

class continuousEntrainment;

/*---------------------------------------------------------------------------*\
                    Class continuousEntrainmentRate Declaration
\*---------------------------------------------------------------------------*/

class continuousEntrainmentRate
{
protected:

    // Protected Data

        //- Reference to the continuous entrainment particle transfer model
        continuousEntrainment& transfer_;

public:

    //- Runtime type information
    TypeName("continuousEntrainmentRate");

    // Declare runtime construction

        declareRunTimeSelectionTable
        (
            autoPtr,
            continuousEntrainmentRate,
            dictionary,
            (
                continuousEntrainment& transfer,
                const dictionary& dict
            ),
            (transfer, dict)
        );

    // Constructors

        continuousEntrainmentRate
        (
            continuousEntrainment& transfer,
            const dictionary& dict
        );

    // Selectors

        static autoPtr<continuousEntrainmentRate> New
        (
            continuousEntrainment& transfer,
            const dictionary& dict
        );


    //- Destructor
    virtual ~continuousEntrainmentRate();

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
