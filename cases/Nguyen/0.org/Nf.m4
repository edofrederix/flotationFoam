FoamFile
{
    version     2.0;
    format      ascii;
    class       volScalarField;
    object      VARNFNAME;
}

dimensions      [0 -3 0 0 0 0 0];

internalField   uniform 0;

boundaryField
{
    inlet
    {
        type            inletOutlet;
        phi             VARNFPHI;
        inletValue      uniform 0;
        value           $internalField;
    }
    outlet
    {
        type            inletOutlet;
        phi             VARNFPHI;
        inletValue      uniform 0;
        value           $internalField;
    }
    walls
    {
        type            zeroGradient;
    }
}
