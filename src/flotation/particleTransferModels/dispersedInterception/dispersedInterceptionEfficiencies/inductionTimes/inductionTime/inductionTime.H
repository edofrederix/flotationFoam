#ifndef inductionTime_H
#define inductionTime_H

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "dictionary.H"
#include "runTimeSelectionTables.H"
#include "fvMesh.H"

namespace Foam
{

namespace particleTransferModels
{

class dispersedInterception;

/*---------------------------------------------------------------------------*\
                        Class inductionTime Declaration
\*---------------------------------------------------------------------------*/

class inductionTime
{
protected:

    // Protected data

        //- Reference to the dispersed deposition particle transfer model
        dispersedInterception& transfer_;

public:

    //- Runtime type information
    TypeName("inductionTime");


    // Declare runtime construction

        declareRunTimeSelectionTable
        (
            autoPtr,
            inductionTime,
            dictionary,
            (
                dispersedInterception& transfer,
                const dictionary& dict
            ),
            (transfer, dict)
        );


    // Static data members


    // Constructors

        inductionTime
        (
            dispersedInterception& transfer,
            const dictionary& dict
        );


    //- Destructor
    virtual ~inductionTime();


    // Selectors

        static autoPtr<inductionTime> New
        (
            dispersedInterception& transfer,
            const dictionary& dict
        );


    // Member Functions

        // Induction time
        virtual dimensionedScalar t(const volScalarField& N) const = 0;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace particleTransferModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
