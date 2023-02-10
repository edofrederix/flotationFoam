FoamFile
{
    version     2.0;
    format      ascii;
    class       volScalarField;
    object      alpha.helium;
}

dimensions      [0 0 0 0 0 0 0];

internalField   uniform 1e-5;

boundaryField
{
    inlet
    {
        type            fixedValue;
        value           uniform VARALPHAHELIUMINLET;
    }
    outlet
    {
        type            inletOutlet;
        phi             phi.helium;
        inletValue      $internalField;
        value           $internalField;
    }
    walls
    {
        type            zeroGradient;
    }

    #include "common"
}
