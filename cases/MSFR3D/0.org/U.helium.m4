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
        type                mappedInternalValue;
        value               $internalField;
        interpolationScheme cell;
        setAverage          true;
        average             (0 0 -1.028);
    }

    bubbles
    {
        type            flowRateInletVelocity;
        massFlowRate    table
        (
            (0 0)
            (1 VARMASSFLOWRATEQ)
        );
        rho             rho.helium;
        value           $internalField;
    }

    outlet
    {
        type            pressureInletOutletVelocity;
        phi             phi.helium;
        value           $internalField;
    }

    "w_.*"
    {
        type            noSlip;
    }

    #include "common"
}
