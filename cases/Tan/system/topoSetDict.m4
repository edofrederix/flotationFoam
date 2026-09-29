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
        name        frother;
        type        cellZoneSet;
        action      new;
        source      boxToCell;
        box         (-1 -1 VARHF) (1 1 1);
    }
);
