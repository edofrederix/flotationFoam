#ifndef infiniteSink_H
#define infiniteSink_H

#include "BrownianAttachmentModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace BrownianAttachmentModels
{

/*---------------------------------------------------------------------------*\
                           Class infiniteSink Declaration
\*---------------------------------------------------------------------------*/

class infiniteSink
:
    public BrownianAttachmentModel
{
    // Private data


public:

    //- Runtime type information
    TypeName("infiniteSink");


    // Constructors

        //- Construct from a dictionary and a mesh
        infiniteSink
        (
            const dictionary& dict,
            const fvMesh& mesh,
            flotationSystem& system,
            const bool registerObject
        );


    //- Destructor
    virtual ~infiniteSink();


    // Member Functions

        //- Brownian attachment rate in [m^3/s]
        virtual tmp<volScalarField> rate(const label& sectionI) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace BrownianAttachmentModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
