FoamFile
{
    version     2.0;
    format      ascii;
    class       volVectorField;
    object      U.helium;
}

dimensions      [0 1 -1 0 0 0 0];

internalField   uniform (0 0 0);

boundaryField
{
    inlet
    {
        type            uniformFixedValue;
        value           $internalField;
        uniformValue    table
        (
            (0 (0 0 0))
            (1 (0 VARUHELIUM 0))
        );
    }
    outlet
    {
        type            pressureInletOutletVelocity;
        phi             phi.helium;
        value           $internalField;
    }
    walls
    {
        type            noSlip;
    }

    #include "common"
}
