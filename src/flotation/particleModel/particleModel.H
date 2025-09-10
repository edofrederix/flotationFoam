#ifndef particleModel_H
#define particleModel_H

#include "phaseSystem.H"
#include "phaseCompressibleMomentumTransportModel.H"

#include "particleSection.H"
#include "particleVelocityModel.H"
#include "particleTransferModel.H"
#include "particleDiffusivityModel.H"

// #include "collisionEfficiencyModel.H"
// #include "attachmentEfficiencyModel.H"
// #include "stabilizationEfficiencyModel.H"
// #include "deterministicAttachmentModel.H"
// #include "stochasticAttachmentModel.H"
// #include "BrownianAttachmentModel.H"
// #include "stochasticDetachmentModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

class flotationSystem;

/*---------------------------------------------------------------------------*\
                  Class particleModel Declaration
\*---------------------------------------------------------------------------*/

class particleModel
:
    public PtrList<particleSection>
{
    // Private data

        //- Reference to the flotation system
        flotationSystem& system_;

        //- Reference to the phase that this particle model belongs to
        const phaseModel& phase_;

        //- Copy of the the phase dictionary
        dictionary dict_;

        //- Turbulent Schmidt number of the particles in this phase
        dimensionedScalar Sct_;

        //- Silence solver output (defaults to true)
        Switch silent_;

        //- Particle velocity model of particles in the associated phase
        autoPtr<particleVelocityModel> velocityModel_;

        //- Brownian diffusivity model of particles in the associated phase
        autoPtr<particleDiffusivityModel> diffusivityModel_;

        //- Particle transfer models
        PtrList<particleTransferModel> sources_;

public:

    // Constructors

        //- Construct from two-phase system
        particleModel
        (
            flotationSystem& system,
            const phaseModel& phase
        );


    //- Destructor
    virtual ~particleModel();


    // Member Functions

        //- Solve for the particle number concentration fields
        List<solverPerformance> solve();

        // Access

            //- Return the phase to which this particle model belongs
            inline const phaseModel& phase() const
            {
                return phase_;
            }

            //- Return the other phase
            const phaseModel& otherPhase() const;

            //- Return the particle model associated with the other phase
            particleModel& otherParticleModel();

            //- Return the flotation system
            inline const flotationSystem& system() const
            {
                return system_;
            }

            //- Particle velocity model of particles in the associated phase
            inline const particleVelocityModel& velocityModel() const
            {
                return velocityModel_;
            }

            //- Brownian diffusivity model of particles in the associated phase
            inline const particleDiffusivityModel& diffusivityModel() const
            {
                return diffusivityModel_;
            }

            //- Particle transfer models
            const PtrList<particleTransferModel>& sources() const
            {
                return sources_;
            }

            //- Return reference to turbulence model of the phase to which this
            //  particle model belongs
            const phaseCompressible::momentumTransportModel& turbulence() const;

            //- Return reference to turbulence model of the other phase
            const phaseCompressible::momentumTransportModel&
                otherPhaseTurbulence() const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
