#ifndef BloomHeindelRate_H
#define BloomHeindelRate_H

#include "continuousTurbulentEntrainmentRate.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace particleTransferModels
{

namespace continuousTurbulentEntrainmentRates
{

/*---------------------------------------------------------------------------*\
                        Class BloomHeindelRate Declaration
\*---------------------------------------------------------------------------*/

class BloomHeindelRate
:
    public continuousTurbulentEntrainmentRate
{
public:

    //- Runtime type information
    TypeName("BloomHeindel");


    // Constructors

        //- Construct from a dictionary and a mesh
        BloomHeindelRate
        (
            continuousTurbulentEntrainment& transfer,
            const dictionary& dict
        );


    //- Destructor
    virtual ~BloomHeindelRate();


    // Member Functions

        //- Deposition rate for given section in [m^3/s]
        virtual tmp<volScalarField> R(const volScalarField& N) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace continuousTurbulentEntrainmentRates
} // End namespace particleTransferModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
