#ifndef idealEfficiency_H
#define idealEfficiency_H

#include "dispersedInterceptionEfficiency.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace particleTransferModels
{

namespace dispersedInterceptionEfficiencies
{

/*---------------------------------------------------------------------------*\
                        Class idealEfficiency Declaration
\*---------------------------------------------------------------------------*/

class idealEfficiency
:
    public dispersedInterceptionEfficiency
{
public:

    //- Runtime type information
    TypeName("ideal");


    // Constructors

        //- Construct from a dictionary and a mesh
        idealEfficiency
        (
            dispersedInterception& transfer,
            const dictionary& dict
        );


    //- Destructor
    virtual ~idealEfficiency();


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
