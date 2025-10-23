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
    // Floor layer

    (0 0 0)
    (VARSC 0 0)
    (VARRC 0 0)
    (VARS 0 0)
    (VARR 0 0)

    (0 VARSC 0)
    (VARSC_MOD VARSC_MOD 0)

    (0 VARRC 0)
    (VARRCSQRT2 VARRCSQRT2 0)
    (VARS VARRCSQRT2 0)
    (VARX10 VARY10 0)

    (0 VARS 0)
    (VARRCSQRT2 VARS 0)
    (VARS_MOD VARS_MOD 0)

    (0 VARR 0)
    (VARY10 VARX10 0)
    (VARRSQRT2 VARRSQRT2 0)

    // Slightly higher layer

    (0 0 VARHO)
    (VARSC 0 VARHO)
    (VARRC 0 VARHO)
    (VARS 0 VARHO)
    (VARR 0 VARHO)

    (0 VARSC VARHO)
    (VARSC_MOD VARSC_MOD VARHO)

    (0 VARRC VARHO)
    (VARRCSQRT2 VARRCSQRT2 VARHO)
    (VARS VARRCSQRT2 VARHO)
    (VARX10 VARY10 VARHO)

    (0 VARS VARHO)
    (VARRCSQRT2 VARS VARHO)
    (VARS_MOD VARS_MOD VARHO)

    (0 VARR VARHO)
    (VARY10 VARX10 VARHO)
    (VARRSQRT2 VARRSQRT2 VARHO)

    // Cone layer

    (0 0 VARHC)
    (VARSC 0 VARHC)
    (VARRC 0 VARHC)
    (VARS 0 VARHC)
    (VARR 0 VARHC)

    (0 VARSC VARHC)
    (VARSC_MOD VARSC_MOD VARHC)

    (0 VARRC VARHC)
    (VARRCSQRT2 VARRCSQRT2 VARHC)
    (VARS VARRCSQRT2 VARHC)
    (VARX10 VARY10 VARHC)

    (0 VARS VARHC)
    (VARRCSQRT2 VARS VARHC)
    (VARS_MOD VARS_MOD VARHC)

    (0 VARR VARHC)
    (VARY10 VARX10 VARHC)
    (VARRSQRT2 VARRSQRT2 VARHC)

    // Cone top surface layer

    (0 0 VARHCPLUS)
    (VARSC 0 VARHCPLUS)
    (0 VARSC VARHCPLUS)
    (VARSC VARSC VARHCPLUS)

    // Inlet layer

    (0 0 VARHI)
    (VARSC 0 VARHI)
    (VARRC 0 VARHI)
    (VARS 0 VARHI)
    (VARR 0 VARHI)

    (0 VARSC VARHI)
    (VARSC_MOD VARSC_MOD VARHI)

    (0 VARRC VARHI)
    (VARRCSQRT2 VARRCSQRT2 VARHI)
    (VARS VARRCSQRT2 VARHI)
    (VARX10 VARY10 VARHI)

    (0 VARS VARHI)
    (VARRCSQRT2 VARS VARHI)
    (VARS_MOD VARS_MOD VARHI)

    (0 VARR VARHI)
    (VARY10 VARX10 VARHI)
    (VARRSQRT2 VARRSQRT2 VARHI)

    // Outer layers

    (0 VARRV 0)
    (VARY75 VARX75 0)
    (VARRVSQRT2 VARRVSQRT2 0)
    (VARX75 VARY75 0)
    (VARRV 0 0)

    (0 VARRV VARHO)
    (VARY75 VARX75 VARHO)
    (VARRVSQRT2 VARRVSQRT2 VARHO)
    (VARX75 VARY75 VARHO)
    (VARRV 0 VARHO)

    (0 VARRV VARHC)
    (VARY75 VARX75 VARHC)
    (VARRVSQRT2 VARRVSQRT2 VARHC)
    (VARX75 VARY75 VARHC)
    (VARRV 0 VARHC)

    (0 VARRV VARHI)
    (VARY75 VARX75 VARHI)
    (VARRVSQRT2 VARRVSQRT2 VARHI)
    (VARX75 VARY75 VARHI)
    (VARRV 0 VARHI)

    // Sink layer

    (0 VARR -VARHS)
    (VARY10 VARX10 -VARHS)
    (VARRSQRT2 VARRSQRT2 -VARHS)
    (VARX10 VARY10 -VARHS)
    (VARR 0 -VARHS)

    (0 VARRV -VARHS)
    (VARY75 VARX75 -VARHS)
    (VARRVSQRT2 VARRVSQRT2 -VARHS)
    (VARX75 VARY75 -VARHS)
    (VARRV 0 -VARHS)
);

blocks
(
    hex (0 1 6 5 17 18 23 22) (VARNSC VARNSC VARNHO) simpleGrading (1 1 1)
    hex (1 2 8 6 18 19 25 23) (VARNRC VARNSC VARNHO) simpleGrading (1 1 1)
    hex (2 3 9 8 19 20 26 25) (VARNS VARNSC VARNHO) simpleGrading (1 1 1)
    hex (3 4 10 9 20 21 27 26) (VARNR VARNSC VARNHO) simpleGrading (1 1 1)
    hex (5 6 8 7 22 23 25 24) (VARNSC VARNRC VARNHO) simpleGrading (1 1 1)
    hex (7 8 12 11 24 25 29 28) (VARNSC VARNS VARNHO) simpleGrading (1 1 1)
    hex (8 9 13 12 25 26 30 29) (VARNS VARNS VARNHO) simpleGrading (1 1 1)
    hex (9 10 16 13 26 27 33 30) (VARNR VARNS VARNHO) simpleGrading (1 1 1)
    hex (11 12 15 14 28 29 32 31) (VARNSC VARNR VARNHO) simpleGrading (1 1 1)
    hex (12 13 16 15 29 30 33 32) (VARNS VARNR VARNHO) simpleGrading (1 1 1)
    hex (4 76 75 10 21 81 80 27) (VARNRV VARNSC VARNHO) simpleGrading (VARG 1 1)
    hex (10 75 74 16 27 80 79 33) (VARNRV VARNS VARNHO) simpleGrading (VARG 1 1)
    hex (14 15 73 72 31 32 78 77) (VARNSC VARNRV VARNHO) simpleGrading (1 VARG 1)
    hex (15 16 74 73 32 33 79 78) (VARNS VARNRV VARNHO) simpleGrading (1 VARG 1)

    hex (17 18 23 22 34 35 40 39) (VARNSC VARNSC VARNHC) simpleGrading (1 1 1)
    hex (18 19 25 23 35 36 42 40) (VARNRC VARNSC VARNHC) simpleGrading (1 1 1)
    hex (19 20 26 25 36 37 43 42) (VARNS VARNSC VARNHC) simpleGrading (1 1 1)
    hex (20 21 27 26 37 38 44 43) (VARNR VARNSC VARNHC) simpleGrading (1 1 1)
    hex (22 23 25 24 39 40 42 41) (VARNSC VARNRC VARNHC) simpleGrading (1 1 1)
    hex (24 25 29 28 41 42 46 45) (VARNSC VARNS VARNHC) simpleGrading (1 1 1)
    hex (25 26 30 29 42 43 47 46) (VARNS VARNS VARNHC) simpleGrading (1 1 1)
    hex (26 27 33 30 43 44 50 47) (VARNR VARNS VARNHC) simpleGrading (1 1 1)
    hex (28 29 32 31 45 46 49 48) (VARNSC VARNR VARNHC) simpleGrading (1 1 1)
    hex (29 30 33 32 46 47 50 49) (VARNS VARNR VARNHC) simpleGrading (1 1 1)
    hex (21 81 80 27 38 86 85 44) (VARNRV VARNSC VARNHC) simpleGrading (VARG 1 1)
    hex (27 80 79 33 44 85 84 50) (VARNRV VARNS VARNHC) simpleGrading (VARG 1 1)
    hex (31 32 78 77 48 49 83 82) (VARNSC VARNRV VARNHC) simpleGrading (1 VARG 1)
    hex (32 33 79 78 49 50 84 83) (VARNS VARNRV VARNHC) simpleGrading (1 VARG 1)

    hex (51 52 54 53 55 56 61 60) (VARNSC VARNSC VARNHI) simpleGrading (1 1 1)
    hex (52 36 42 54 56 57 63 61) (VARNRC VARNSC VARNHI) simpleGrading (1 1 1)
    hex (36 37 43 42 57 58 64 63) (VARNS VARNSC VARNHI) simpleGrading (1 1 1)
    hex (37 38 44 43 58 59 65 64) (VARNR VARNSC VARNHI) simpleGrading (1 1 1)
    hex (53 54 42 41 60 61 63 62) (VARNSC VARNRC VARNHI) simpleGrading (1 1 1)
    hex (41 42 46 45 62 63 67 66) (VARNSC VARNS VARNHI) simpleGrading (1 1 1)
    hex (42 43 47 46 63 64 68 67) (VARNS VARNS VARNHI) simpleGrading (1 1 1)
    hex (43 44 50 47 64 65 71 68) (VARNR VARNS VARNHI) simpleGrading (1 1 1)
    hex (45 46 49 48 66 67 70 69) (VARNSC VARNR VARNHI) simpleGrading (1 1 1)
    hex (46 47 50 49 67 68 71 70) (VARNS VARNR VARNHI) simpleGrading (1 1 1)
    hex (38 86 85 44 59 91 90 65) (VARNRV VARNSC VARNHI) simpleGrading (VARG 1 1)
    hex (44 85 84 50 65 90 89 71) (VARNRV VARNS VARNHI) simpleGrading (VARG 1 1)
    hex (48 49 83 82 69 70 88 87) (VARNSC VARNRV VARNHI) simpleGrading (1 VARG 1)
    hex (49 50 84 83 70 71 89 88) (VARNS VARNRV VARNHI) simpleGrading (1 VARG 1)

    hex (96 101 100 95 4 76 75 10) (VARNRV VARNSC VARNHS) simpleGrading (VARG 1 1)
    hex (95 100 99 94 10 75 74 16) (VARNRV VARNS VARNHS) simpleGrading (VARG 1 1)
    hex (92 93 98 97 14 15 73 72) (VARNSC VARNRV VARNHS) simpleGrading (1 VARG 1)
    hex (93 94 99 98 15 16 74 73) (VARNS VARNRV VARNHS) simpleGrading (1 VARG 1)
);

edges
(
    arc 2 8 45 (0 0 1)
    arc 8 7 45 (0 0 1)

    arc 4 10 VARTHETA (0 0 1)
    arc 10 16 VARGAMMA (0 0 1)
    arc 16 15 VARGAMMA (0 0 1)
    arc 15 14 VARTHETA (0 0 1)

    arc 76 75 VARTHETA (0 0 1)
    arc 75 74 VARGAMMA (0 0 1)
    arc 74 73 VARGAMMA (0 0 1)
    arc 73 72 VARTHETA (0 0 1)


    arc 19 25 45 (0 0 1)
    arc 25 24 45 (0 0 1)

    arc 21 27 VARTHETA (0 0 1)
    arc 27 33 VARGAMMA (0 0 1)
    arc 33 32 VARGAMMA (0 0 1)
    arc 32 31 VARTHETA (0 0 1)

    arc 81 80 VARTHETA (0 0 1)
    arc 80 79 VARGAMMA (0 0 1)
    arc 79 78 VARGAMMA (0 0 1)
    arc 78 77 VARTHETA (0 0 1)

    arc 36 42 45 (0 0 1)
    arc 42 41 45 (0 0 1)

    arc 38 44 VARTHETA (0 0 1)
    arc 44 50 VARGAMMA (0 0 1)
    arc 50 49 VARGAMMA (0 0 1)
    arc 49 48 VARTHETA (0 0 1)

    arc 86 85 VARTHETA (0 0 1)
    arc 85 84 VARGAMMA (0 0 1)
    arc 84 83 VARGAMMA (0 0 1)
    arc 83 82 VARTHETA (0 0 1)


    arc 57 63 45 (0 0 1)
    arc 63 62 45 (0 0 1)

    arc 59 65 VARTHETA (0 0 1)
    arc 65 71 VARGAMMA (0 0 1)
    arc 71 70 VARGAMMA (0 0 1)
    arc 70 69 VARTHETA (0 0 1)

    arc 91 90 VARTHETA (0 0 1)
    arc 90 89 VARGAMMA (0 0 1)
    arc 89 88 VARGAMMA (0 0 1)
    arc 88 87 VARTHETA (0 0 1)


    arc 96 95 VARTHETA (0 0 1)
    arc 95 94 VARGAMMA (0 0 1)
    arc 94 93 VARGAMMA (0 0 1)
    arc 93 92 VARTHETA (0 0 1)

    arc 101 100 VARTHETA (0 0 1)
    arc 100 99 VARGAMMA (0 0 1)
    arc 99 98 VARGAMMA (0 0 1)
    arc 98 97 VARTHETA (0 0 1)
);

boundary
(
    outlet
    {
        type    patch;
        faces
        (
            (101 100 75 76)
            (100 99 74 75)
            (99 98 73 74)
            (98 97 72 73)
        );
    }

    wall_cone
    {
        type    wall;
        faces
        (
            (51 52 54 53)
            (52 36 42 54)
            (53 54 42 41)

            (34 35 40 39)
            (35 36 42 40)
            (39 40 42 41)
        );
    }

    wall_vessel
    {
        type    wall;
        faces
        (
            (76 75 80 81)
            (75 74 79 80)
            (74 73 78 79)
            (73 72 77 78)
            (81 80 85 86)
            (80 79 84 85)
            (79 78 83 84)
            (78 77 82 83)
            (86 85 90 91)
            (85 84 89 90)
            (84 83 88 89)
            (83 82 87 88)
        );
    }

    wall_top
    {
        type    wall;
        faces
        (
            (55 56 61 60)
            (56 57 63 61)
            (60 61 63 62)
            (57 58 64 63)
            (58 59 65 64)
            (62 63 67 66)
            (63 64 68 67)
            (64 65 71 68)
            (66 67 70 69)
            (67 68 71 70)
            (59 91 90 65)
            (65 90 89 71)
            (71 89 88 70)
            (69 70 88 87)
        );
    }

    wall_floor
    {
        type    wall;
        faces
        (
            (1 0 5 6)
            (2 1 6 8)
            (3 2 8 9)
            (4 3 9 10)
            (6 5 7 8)
            (8 7 11 12)
            (9 8 12 13)
            (10 9 13 16)
            (12 11 14 15)
            (13 12 15 16)

            (101 96 95 100)
            (100 95 94 99)
            (99 94 93 98)
            (98 93 92 97)

            (92 93 15 14)
            (93 94 16 15)
            (94 95 10 16)
            (95 96 4 10)
        );
    }

    sides
    {
        type    symmetry;
        faces
        (
            (0 1 18 17)
            (1 2 19 18)
            (2 3 20 19)
            (3 4 21 20)
            (4 76 81 21)
            (17 18 35 34)
            (18 19 36 35)
            (19 20 37 36)
            (20 21 38 37)
            (21 81 86 38)
            (51 52 56 55)
            (52 36 57 56)
            (36 37 58 57)
            (37 38 59 58)
            (38 86 91 59)

            (72 14 31 77)
            (14 11 28 31)
            (11 7 24 28)
            (7 5 22 24)
            (5 0 17 22)
            (77 31 48 82)
            (31 28 45 48)
            (28 24 41 45)
            (24 22 39 41)
            (22 17 34 39)
            (82 48 69 87)
            (48 45 66 69)
            (45 41 62 66)
            (41 53 60 62)
            (53 51 55 60)

            (96 101 76 4)
            (97 92 14 72)
        );
    }
);
