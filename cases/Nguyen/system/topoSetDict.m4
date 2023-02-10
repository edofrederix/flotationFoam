FoamFile
{
    format      ascii;
    class       dictionary;
    location    "system";
    object      topSetDict;
}

actions
(
    {
        name    frotherCellSet;
        type    cellSet;
        action  new;
        source  boxToCell;
        sourceInfo
        {
            box (-1 -1 VARHF) (1 1 1);
        }
    }

    {
        name    frother;
        type    cellZoneSet;
        action  new;
        source  setToCellZone;
        sourceInfo
        {
            set frotherCellSet;
        }
    }

);
