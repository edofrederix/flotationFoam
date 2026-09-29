FoamFile
{
    version     2.0;
    format      ascii;
    class       dictionary;
    object      setFieldsDict;
}

defaultFieldValues
(
    volScalarFieldValue alpha.nitrogen 0.99
    volScalarFieldValue alpha.water    0.01
);

regions
(
    boxToCell
    {
        box (-1 -1 -1) (1 1 VARHL);
        fieldValues
        (
            volScalarFieldValue alpha.nitrogen 0.01
            volScalarFieldValue alpha.water    0.99
        );
    }
);
