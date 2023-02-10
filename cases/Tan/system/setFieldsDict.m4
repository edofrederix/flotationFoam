FoamFile
{
    format      ascii;
    class       dictionary;
    location    "system";
    object      setFieldsDict;
}

defaultFieldValues
(
    volScalarFieldValue alpha.nitrogen 1
    volScalarFieldValue alpha.water 0
);

regions
(
    boxToCell
    {
        box (-1 -1 -1) (1 1 VARHL);

        fieldValues
        (
            volScalarFieldValue alpha.nitrogen 0
            volScalarFieldValue alpha.water 1

            #include "NfFieldValues"
        );
    }
);
