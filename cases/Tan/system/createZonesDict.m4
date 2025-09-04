FoamFile
{
    format      ascii;
    class       dictionary;
    location    "system";
    object      createZonesDict;
}

frother
{
    type        box;
    zoneType    cell;
    box         (-1 -1 VARHF) (1 1 1);
}
