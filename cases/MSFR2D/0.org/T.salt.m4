FoamFile
{
    version     2.0;
    format      ascii;
    class       volScalarField;
    object      T.salt;
}

dimensions      [0 0 0 1 0 0 0];

internalField   uniform VARTINLET;

boundaryField
{
    inlet
    {
        type            fixedValue;
        value           uniform VARTINLET;
    }
    outlet
    {
        type            zeroGradient;
    }
    walls
    {
        type            zeroGradient;
    }

    #include "common"
}
