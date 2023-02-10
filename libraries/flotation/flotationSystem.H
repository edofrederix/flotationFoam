#ifndef flotationSystem_H
#define flotationSystem_H

#include "IOdictionary.H"
#include "volFields.H"
#include "phaseSystem.H"
#include "dispersedPhaseInterface.H"
#include "phaseCompressibleMomentumTransportModel.H"

#include "sectionalDistribution.H"
#include "freeParticleSection.H"
#include "capturedParticleSection.H"
#include "particleVelocityModel.H"
#include "BrownianDiffusivityModel.H"
#include "collisionEfficiencyModel.H"
#include "attachmentEfficiencyModel.H"
#include "stabilizationEfficiencyModel.H"
#include "deterministicAttachmentModel.H"
#include "stochasticAttachmentModel.H"
#include "BrownianAttachmentModel.H"
#include "stochasticDetachmentModel.H"

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

        //- Turbulent Schmidt number
        dimensionedScalar Sct_;

        //- Phase pair for dispersed phase in continuous phase
        autoPtr<dispersedPhaseInterface> twoPhasePair_;

        //- Sectional distribution
        autoPtr<sectionalDistribution> distribution_;

        //- List of free particle sections
        PtrList<freeParticleSection> freeParticles_;

        //- List of captured particle sections
        PtrList<capturedParticleSection> capturedParticles_;

        //- Particle velocity model
        autoPtr<particleVelocityModel> particleVelocity_;

        //- Brownian diffusivity model
        autoPtr<BrownianDiffusivityModel> BrownDiff_;

        //- Particle collision efficiency model
        autoPtr<collisionEfficiencyModel> colEff_;

        //- Particle attachment efficiency model
        autoPtr<attachmentEfficiencyModel> attEff_;

        //- Particle stabilization efficiency model
        autoPtr<stabilizationEfficiencyModel> stabEff_;

        //- Deterministic attachment model
        autoPtr<deterministicAttachmentModel> detAttachRate_;

        //- Stochastic attachment model
        autoPtr<stochasticAttachmentModel> stochAttachRate_;

        //- Brownian attachment model
        autoPtr<BrownianAttachmentModel> BrownAttachRate_;

        //- Stochastic detachment model
        autoPtr<stochasticDetachmentModel> stochDetachRate_;

        //- Collision efficiencies
        PtrList<volScalarField> Pcol_;

        //- Attachment efficiencies
        PtrList<volScalarField> Patt_;

        //- Stabilization efficiencies
        PtrList<volScalarField> Pstab_;

    // Private member functions


public:

    // Constructors

        //- Construct from two-phase system
        flotationSystem
        (
            const phaseSystem& fluid,
            const fvMesh& mesh
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

            //- Return the ordered phase pair
            inline const dispersedPhaseInterface& twoPhasePair() const
            {
                return twoPhasePair_();
            }

            //- Return the sectional distribution
            inline sectionalDistribution& distribution()
            {
                return distribution_();
            }

            inline const sectionalDistribution& distribution() const
            {
                return distribution_();
            }

            //- Return the list of free particle sections
            inline PtrList<freeParticleSection>& freeParticles()
            {
                return freeParticles_;
            }

            inline const PtrList<freeParticleSection>& freeParticles() const
            {
                return freeParticles_;
            }

            //- Return the list of captured particle sections
            inline PtrList<capturedParticleSection>& capturedParticles()
            {
                return capturedParticles_;
            }

            inline const PtrList<capturedParticleSection>& capturedParticles() const
            {
                return capturedParticles_;
            }

            inline const BrownianDiffusivityModel& BrownDiff() const
            {
                return BrownDiff_;
            }

            //- Return reference to turbulence model of the continuous phase
            const phaseCompressible::momentumTransportModel&
                continuousTurbulence() const;

        // Non-dimensional numbers

            //- Diameter-based bubble Reynolds number
            inline tmp<volScalarField> Re() const
            {
                return twoPhasePair().Re();
            }

            //- Diameter-based bubble Eötvös number
            inline tmp<volScalarField> Eo() const
            {
                return twoPhasePair().Eo();
            }

            //- Schmidt number given the particle diffusivity
            inline tmp<volScalarField> Sc(const volScalarField& D) const
            {
                return twoPhasePair().continuous().thermo().nu()/D;
            }
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
