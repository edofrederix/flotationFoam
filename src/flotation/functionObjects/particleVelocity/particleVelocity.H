#ifndef particleVelocity_functionObject_H
#define particleVelocity_functionObject_H

#include "fieldExpression.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

class flotationSystem;

namespace functionObjects
{

/*---------------------------------------------------------------------------*\
                       Class particleVelocity Declaration
\*---------------------------------------------------------------------------*/

class particleVelocity
:
    public fieldExpression
{
    // Private Data

        //- Flotation particle system pointer
        const flotationSystem* systemPtr_;

        //- Section number
        label sectionNum_;

        //- Dictionary name (defaults to flotationProperties)
        word dictName_;

        //- Name of the phase to which the particles belong
        word phaseName_;

    // Private Member Functions

        //- Calculate the particleVelocity field and return true if successful
        virtual bool calc();


public:

    //- Runtime type information
    TypeName("particleVelocity");


    // Constructors

        //- Construct from Time and dictionary
        particleVelocity
        (
            const word& name,
            const Time& runTime,
            const dictionary& dict
        );


    //- Destructor
    virtual ~particleVelocity();
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace functionObjects
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
