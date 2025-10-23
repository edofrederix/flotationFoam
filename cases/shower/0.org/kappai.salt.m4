FoamFile
{
    version     2.0;
    format      ascii;
    class       volScalarField;
    object      kappai.salt;
}

dimensions      [0 -1 0 0 0 0 0];

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
        type            zeroGradient;
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
