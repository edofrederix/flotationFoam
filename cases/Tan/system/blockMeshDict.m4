FoamFile
{
    version     2.0;
    format      ascii;
    class       dictionary;
    object      blockMeshDict;
}

convertToMeters 1;

vertices
(
    (-VARA -VARA 0)
    ( VARA -VARA 0)
    (-VARA  VARA 0)
    ( VARA  VARA 0)

    (-VARB -VARB 0)
    ( VARB -VARB 0)
    (-VARB  VARB 0)
    ( VARB  VARB 0)

    (-VARA -VARA VARH)
    ( VARA -VARA VARH)
    (-VARA  VARA VARH)
    ( VARA  VARA VARH)

    (-VARB -VARB VARH)
    ( VARB -VARB VARH)
    (-VARB  VARB VARH)
    ( VARB  VARB VARH)
);

blocks
(
    hex (0 1 3 2 8 9 11 10) (VARNA VARNA VARNH) simpleGrading (1 1 1)
    hex (4 5 1 0 12 13 9 8) (VARNA VARNB VARNH) simpleGrading (1 1 1)
    hex (5 7 3 1 13 15 11 9) (VARNA VARNB VARNH) simpleGrading (1 1 1)
    hex (7 6 2 3 15 14 10 11) (VARNA VARNB VARNH) simpleGrading (1 1 1)
    hex (6 4 0 2 14 12 8 10) (VARNA VARNB VARNH) simpleGrading (1 1 1)
);

edges
(
    arc 4 5 (0 -VARR 0)
    arc 5 7 (VARR 0 0)
    arc 7 6 (0 VARR 0)
    arc 6 4 (-VARR 0 0)

    arc 12 13 (0 -VARR VARH)
    arc 13 15 (VARR 0 VARH)
    arc 15 14 (0 VARR VARH)
    arc 14 12 (-VARR 0 VARH)

    arc 0 1 (0 -VARC 0)
    arc 1 3 (VARC 0 0)
    arc 3 2 (0 VARC 0)
    arc 2 0 (-VARC 0 0)

    arc 8 9 (0 -VARC VARH)
    arc 9 11 (VARC 0 VARH)
    arc 11 10 (0 VARC VARH)
    arc 10 8 (-VARC 0 VARH)
);

patches
(
    patch inlet
    (
        (0 1 3 2)
        (4 5 1 0)
        (5 7 3 1)
        (7 6 2 3)
        (6 4 0 2)
    )
    patch outlet
    (
        (9 8 10 11)
        (13 12 8 9)
        (12 14 10 8)
        (14 15 11 10)
        (15 13 9 11)
    )
    wall walls
    (
        (5 13 15 7)
        (7 15 14 6)
        (6 14 12 4)
        (4 12 13 5)
    )
);

mergePatchPairs
(
);
