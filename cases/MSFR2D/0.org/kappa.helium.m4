FoamFile
{
    version     2.0;
    format      ascii;
    class       volScalarField;
    object      kappa.helium;
}

dimensions      [0 -1 0 0 0 0 0];

internalField   uniform 0.0;

boundaryField
{
    inlet
    {
        type            inletOutletLogNormal;
        phi             alphaPhi.helium;
        sigma           VARSIGMA;
        dsm             VARDSM;
        alphaName       helium;
        value           $internalField;
    }
    outlet
    {
        type            inletOutletLogNormal;
        phi             alphaPhi.helium;
        sigma           VARSIGMA;
        dsm             VARDSM;
        alphaName       helium;
        value           $internalField;
    }
    walls
    {
        type            zeroGradient;
    }

    #include "common"
}
