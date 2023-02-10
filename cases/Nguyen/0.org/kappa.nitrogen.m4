FoamFile
{
    version     2.0;
    format      ascii;
    class       volScalarField;
    object      kappa.nitrogen;
}

dimensions      [0 -1 0 0 0 0 0];

internalField   uniform 0.0;

boundaryField
{
    inlet
    {
        type            inletOutletLogNormal;
        phi             alphaPhi.nitrogen;
        sigma           VARSIGMA;
        dsm             VARDSM;
        alphaName       nitrogen;
        value           $internalField;
    }
    outlet
    {
        type            inletOutletLogNormal;
        phi             alphaPhi.nitrogen;
        sigma           VARSIGMA;
        dsm             VARDSM;
        alphaName       nitrogen;
        value           $internalField;
    }
    walls
    {
        type            zeroGradient;
    }
}
