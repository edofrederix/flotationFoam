FoamFile
{
    format      ascii;
    class       dictionary;
    location    "system";
    object      setFieldsDict;
}

defaultValues
{
    alpha.nitrogen  0.99;
    alpha.water     0.01;
}

zones
{
    water
    {
        type        box;
        zoneType    cell;

        box         (-1 -1 -1) (1 1 VARHL);

        values
        {
            alpha.nitrogen  0.01;
            alpha.water     0.99;

            #include "NfFieldValues"
        }
    }
}
