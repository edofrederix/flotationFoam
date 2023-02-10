FoamFile
{
    version     2.0;
    format      ascii;
    class       volScalarField;
    object      alpha.salt;
}

dimensions      [0 0 0 0 0 0 0];

internalField   uniform 0.99999;

boundaryField
{
    inlet
    {
        type            fixedValue;
        value           uniform VARALPHASALTINLET;
    }
    outlet
    {
        type            inletOutlet;
        phi             phi.salt;
        inletValue      $internalField;
        value           $internalField;
    }
    walls
    {
        type            zeroGradient;
    }

    #include "common"
}
