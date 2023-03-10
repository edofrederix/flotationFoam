FoamFile
{
    version     2.0;
    format      ascii;
    class       volScalarField;
    object      lambda.air;
}

dimensions      [0 -3 0 0 0 0 0];

internalField   uniform 0.0;

boundaryField
{
    inlet
    {
        type            inletOutletLogNormal;
        phi             phi.air;
        sigma           VARSIGMA;
        dsm             VARDSM;
        alphaName       air;
        value           $internalField;
    }
    outlet
    {
        type            inletOutlet;
        phi             phi.air;
        inletValue      $internalField;
        value           $internalField;
    }
    walls
    {
        type            zeroGradient;
    }
    empties
    {
        type            empty;
    }
}
