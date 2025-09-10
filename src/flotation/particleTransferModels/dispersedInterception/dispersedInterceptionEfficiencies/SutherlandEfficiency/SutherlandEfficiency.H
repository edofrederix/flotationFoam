#ifndef SutherlandEfficiency_H
#define SutherlandEfficiency_H

#include "dispersedInterceptionEfficiency.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace particleTransferModels
{

namespace dispersedInterceptionEfficiencies
{

/*---------------------------------------------------------------------------*\
                        Class SutherlandEfficiency Declaration
\*---------------------------------------------------------------------------*/

class SutherlandEfficiency
:
    public dispersedInterceptionEfficiency
{
    // Private data


public:

    //- Runtime type information
    TypeName("Sutherland");


    // Constructors

        //- Construct from a dictionary and a mesh
        SutherlandEfficiency
        (
            dispersedInterception& transfer,
            const dictionary& dict
        );


    //- Destructor
    virtual ~SutherlandEfficiency();


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
