FoamFile
{
    version     2.0;
    format      ascii;
    class       dictionary;
    object      topoSetDict;
}

actions
(
    {
        name        vessel;
        type        cellZoneSet;
        action      new;
        source      boxToCell;
        box         (0 -10 -10) (1.1275 10 10);
    }
);
