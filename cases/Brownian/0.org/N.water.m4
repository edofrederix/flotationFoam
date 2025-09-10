FoamFile
{
    version     2.0;
    format      ascii;
    class       volScalarField;
    location    "0";
    object      VARNFNAME;
}

dimensions      [0 -3 0 0 0 0 0];

internalField   uniform VARNF;

boundaryField
{
    inlet
    {
        type            inletOutlet;
        phi             VARNFPHI;
        inletValue      $internalField;
        value           $internalField;
    }
    outlet
    {
        type            inletOutlet;
        phi             VARNFPHI;
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
