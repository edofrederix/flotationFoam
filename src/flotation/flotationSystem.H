#ifndef flotationSystem_H
#define flotationSystem_H

#include "IOdictionary.H"
#include "phaseSystem.H"
#include "phaseInterface.H"
#include "particleSizeDistribution.H"
#include "particleModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                  Class flotationSystem Declaration
\*---------------------------------------------------------------------------*/

class flotationSystem
:
    public IOdictionary
{
    // Private data

        //- Reference to the two-phase system
        const phaseSystem& fluid_;

        //- Reference to the mesh
        const fvMesh& mesh_;

        //- Particle density
        dimensionedScalar rho_;

        //- Number of corrections (defaults to 2)
        label nCorr_;

        //- Phase interface
        phaseInterface interface_;

        //- Sectional distribution
        autoPtr<particleSizeDistribution> distribution_;

        //- First and second phase particle model
        PtrList<particleModel> particleModels_;

public:

    //- Return the section index from a field whose name is in the format <field
    //  name>.<phase name>:<section number>. Note that the returned number is
    //  subtracted by 1 so that the first number is zero.
    static label sectionNum(const volScalarField&);

    //- Runtime type information
    TypeName("flotationSystem");

    // Constructors

        //- Construct from two-phase system
        flotationSystem
        (
            const phaseSystem& fluid,
            const fvMesh& mesh,
            const word dictName = ""
        );


    //- Destructor
    virtual ~flotationSystem();


    // Member Functions

        //- Solve for the particle number concentration fields
        void solve();

        //- Read base phaseProperties dictionary
        bool read();

        // Access

            //- Return the two-phase system
            inline const phaseSystem& fluid() const
            {
                return fluid_;
            }

            //- Return the mesh
            inline const fvMesh& mesh() const
            {
                return mesh_;
            }

            //- Return particle density
            inline const dimensionedScalar& rho() const
            {
                return rho_;
            }

            //- Return the phase interface
            inline const phaseInterface& interface() const
            {
                return interface_;
            }

            //- Return the particle size distribution
            inline particleSizeDistribution& distribution()
            {
                return distribution_();
            }

            inline const particleSizeDistribution& distribution() const
            {
                return distribution_();
            }

            //- Return the list of particle models for each phase
            inline PtrList<particleModel>& models()
            {
                return particleModels_;
            }

            inline const PtrList<particleModel>& models() const
            {
                return particleModels_;
            }

            // Return the first phase particle model
            inline particleModel& model1()
            {
                return particleModels_[0];
            }

            inline const particleModel& model1() const
            {
                return particleModels_[0];
            }

            // Return the second phase particle model
            inline particleModel& model2()
            {
                return particleModels_[1];
            }

            inline const particleModel& model2() const
            {
                return particleModels_[1];
            }

            //- Return reference to turbulence model of the first phase
            const phaseCompressible::momentumTransportModel&
                firstPhaseTurbulence() const;

            //- Return reference to turbulence model of the second phase
            const phaseCompressible::momentumTransportModel&
                secondPhaseTurbulence() const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
