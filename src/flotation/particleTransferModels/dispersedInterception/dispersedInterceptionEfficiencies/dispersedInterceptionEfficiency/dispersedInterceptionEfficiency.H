#ifndef dispersedInterceptionEfficiency_H
#define dispersedInterceptionEfficiency_H

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "dictionary.H"
#include "runTimeSelectionTables.H"
#include "fvMesh.H"
#include "inductionTime.H"

namespace Foam
{

namespace particleTransferModels
{

class dispersedInterception;

/*---------------------------------------------------------------------------*\
                Class dispersedInterceptionEfficiency Declaration
\*---------------------------------------------------------------------------*/

class dispersedInterceptionEfficiency
{
protected:

    // Protected data

        //- Reference to the dispersed deposition particle transfer model
        dispersedInterception& transfer_;

        //- Dictionary
        dictionary dict_;

        //- Induction time
        autoPtr<inductionTime> induction_;

    // Protected Member Functions

        //- On-demand initialization of induction time
        void setInductionTime();

public:

    //- Runtime type information
    TypeName("dispersedInterceptionEfficiency");


    // Declare runtime construction

        declareRunTimeSelectionTable
        (
            autoPtr,
            dispersedInterceptionEfficiency,
            dictionary,
            (
                dispersedInterception& transfer,
                const dictionary& dict
            ),
            (transfer, dict)
        );


    // Constructors

        dispersedInterceptionEfficiency
        (
            dispersedInterception& transfer,
            const dictionary& dict
        );


    //- Destructor
    virtual ~dispersedInterceptionEfficiency();


    // Selectors

        static autoPtr<dispersedInterceptionEfficiency> New
        (
            dispersedInterception& transfer,
            const dictionary& dict
        );


    // Member Functions

        //- Clip an dispersedInterceptionEfficiency field
        tmp<volScalarField> clip(const tmp<volScalarField>& E) const;

        //- Particle-bubble diameter ratio
        tmp<volScalarField> R(const volScalarField& N) const;

        // Efficiency
        virtual tmp<volScalarField> E(const volScalarField& N) const = 0;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace particleTransferModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
