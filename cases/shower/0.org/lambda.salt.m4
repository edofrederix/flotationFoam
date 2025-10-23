FoamFile
{
    version     2.0;
    format      ascii;
    class       volScalarField;
    object      lambda.salt;
}

dimensions      [0 -3 0 0 0 0 0];

internalField   uniform 0.0;

boundaryField
{
    inlet
    {
        type            inletOutletLogNormal;
        phi             phi.salt;
        sigma           VARSIGMA;
        dsm             VARDSM;
        value           $internalField;
    }

    outlet
    {
        type            inletOutlet;
        phi             phi.salt;
        inletValue      $internalField;
        value           $internalField;
    }

    "wall\_.*"
    {
        type            zeroGradient;
    }

    sides
    {
        type            symmetry;
    }
}
