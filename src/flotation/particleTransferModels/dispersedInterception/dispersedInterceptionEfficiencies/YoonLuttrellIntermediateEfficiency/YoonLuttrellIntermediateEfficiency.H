#ifndef YoonLuttrellIntermediateEfficiency_H
#define YoonLuttrellIntermediateEfficiency_H

#include "dispersedInterceptionEfficiency.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace particleTransferModels
{

namespace dispersedInterceptionEfficiencies
{

/*---------------------------------------------------------------------------*\
                Class YoonLuttrellIntermediateEfficiency Declaration
\*---------------------------------------------------------------------------*/

class YoonLuttrellIntermediateEfficiency
:
    public dispersedInterceptionEfficiency
{
public:

    //- Runtime type information
    TypeName("YoonLuttrellIntermediate");


    // Constructors

        //- Construct from a dictionary and a mesh
        YoonLuttrellIntermediateEfficiency
        (
            dispersedInterception& transfer,
            const dictionary& dict
        );


    //- Destructor
    virtual ~YoonLuttrellIntermediateEfficiency();


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
