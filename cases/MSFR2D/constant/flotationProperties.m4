FoamFile
{
    version     2.0;
    format      ascii;
    class       dictionary;
    location    "constant";
    object      flotationParticleProperties;
}

rho                 1e4;

Sct                 1.0;

continuousPhaseName salt;
dispersedPhaseName  helium;

sectionalDistribution
{
    type        logarithmic;
    dMin        VARDMIN;
    dMax        VARDMAX;
    N           VARNSECTIONS;
}

particleVelocityModel
{
    type        localEquilibrium;
    steadyState false;
}

BrownianDiffusivityModel
{
    type        StokesEinstein;
    f           1.0;
}

efficiencyModels
{
    collisions
    {
        type    YoonLuttrellIntermediate;
    }
    attachment
    {
        type    YoonLuttrellIntermediate;

        inductionTime
        {
            type    Dai;
            A       0.05;
            B       0.6;
        }
    }
    stabilization
    {
        type    ideal;
    }
}

interactionModels
{
    attachment
    {
        deterministic
        {
            type    spherical;
        }
        stochastic
        {
            type    none;
        }
        Brownian
        {
            type    infiniteSink;

            SherwoodCorrelation
            {
                type    RanzMarshall;
            }
        }
    }
    detachment
    {
        stochastic
        {
            type    none;
        }
    }
}
