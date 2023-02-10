FoamFile
{
    version     2.0;
    format      ascii;
    class       volScalarField;
    object      VARNFNAME;
}

dimensions      [0 -3 0 0 0 0 0];

internalField   uniform VARNF;

boundaryField
{
    inlet
    {
        type            zeroGradient;

    /*
        type            inletOutlet;
        phi             VARNFPHI;
        inletValue      uniform 0;
        value           $internalField;
    */
    }
    outlet
    {
        type            zeroGradient;

    /*
        type            inletOutlet;
        phi             VARNFPHI;
        inletValue      uniform 0;
        value           $internalField;
    */
    }
    walls
    {
        type            zeroGradient;
    }

    #include "common"
}
