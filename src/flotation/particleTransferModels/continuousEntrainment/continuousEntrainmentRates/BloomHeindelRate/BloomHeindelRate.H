#ifndef BloomHeindelRate_H
#define BloomHeindelRate_H

#include "continuousEntrainmentRate.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace particleTransferModels
{

namespace continuousEntrainmentRates
{

/*---------------------------------------------------------------------------*\
                        Class BloomHeindelRate Declaration
\*---------------------------------------------------------------------------*/

class BloomHeindelRate
:
    public continuousEntrainmentRate
{
public:

    //- Runtime type information
    TypeName("BloomHeindel");


    // Constructors

        //- Construct from a dictionary and a mesh
        BloomHeindelRate
        (
            continuousEntrainment& transfer,
            const dictionary& dict
        );


    //- Destructor
    virtual ~BloomHeindelRate();


    // Member Functions

        //- Deposition rate for given section in [m^3/s]
        virtual tmp<volScalarField> R(const volScalarField& N) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace continuousEntrainmentRates
} // End namespace particleTransferModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
