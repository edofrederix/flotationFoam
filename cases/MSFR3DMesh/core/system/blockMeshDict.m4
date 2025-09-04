FoamFile
{
    format      ascii;
    class       dictionary;
    object      blockMeshDict;
}

convertToMeters 1;

vertices
(
    (VARCR00 0.0 VARCZ00)   // 0
    (VARCR01 0.0 VARCZ01)
    (VARCR02 0.0 VARCZ02)
    (VARCR03 0.0 VARCZ03)

    (VARCR10 0.0 VARCZ10)   // 4
    (VARCR11 0.0 VARCZ11)
    (VARCR12 0.0 VARCZ12)
    (VARCR13 0.0 VARCZ13)

    (VARCR20 0.0 VARCZ20)   // 8
    (VARCR21 0.0 VARCZ21)
    (VARCR22 0.0 VARCZ22)
    (VARCR23 0.0 VARCZ23)


    (VARCR01M VARCR01M VARCZ01M)   // 12
    (VARCR02M VARCR02M VARCZ02M)
    (VARCR03M VARCR03M VARCZ03M)

    (VARCR11M VARCR11M VARCZ11M)   // 15
    (VARCR12M VARCR12M VARCZ12M)
    (VARCR13M VARCR13M VARCZ13M)

    (VARCR21M VARCR21M VARCZ21M)   // 18
    (VARCR22M VARCR22M VARCZ22M)
    (VARCR23M VARCR23M VARCZ23M)


    (0.0 VARCR00 VARCZ00)   // 21
    (0.0 VARCR01 VARCZ01)
    (0.0 VARCR02 VARCZ02)
    (0.0 VARCR03 VARCZ03)

    (0.0 VARCR10 VARCZ10)   // 25
    (0.0 VARCR11 VARCZ11)
    (0.0 VARCR12 VARCZ12)
    (0.0 VARCR13 VARCZ13)

    (0.0 VARCR20 VARCZ20)   // 29
    (0.0 VARCR21 VARCZ21)
    (0.0 VARCR22 VARCZ22)
    (0.0 VARCR23 VARCZ23)
);

blocks
(
    hex (0 1 12 22 4 5 15 26) (VARCNR0 VARCNR0 VARCNZ0) simpleGrading (1 1 1)
    hex (1 2 13 12 5 6 16 15) (VARCNR1 VARCNR0 VARCNZ0) simpleGrading (1 1 1)
    hex (12 13 23 22 15 16 27 26) (VARCNR1 VARCNR0 VARCNZ0) simpleGrading (1 1 1)
    hex (2 3 14 13 6 7 17 16) (VARCNR2 VARCNR0 VARCNZ0) simpleGrading (1 1 1)
    hex (13 14 24 23 16 17 28 27) (VARCNR2 VARCNR0 VARCNZ0) simpleGrading (1 1 1)

    hex (4 5 15 26 8 9 18 30) (VARCNR0 VARCNR0 VARCNZ1) simpleGrading (1 1 1)
    hex (5 6 16 15 9 10 19 18) (VARCNR1 VARCNR0 VARCNZ1) simpleGrading (1 1 1)
    hex (15 16 27 26 18 19 31 30) (VARCNR1 VARCNR0 VARCNZ1) simpleGrading (1 1 1)
    hex (6 7 17 16 10 11 20 19) (VARCNR2 VARCNR0 VARCNZ1) simpleGrading (1 1 1)
    hex (16 17 28 27 19 20 32 31) (VARCNR2 VARCNR0 VARCNZ1) simpleGrading (1 1 1)
);

edges
(
    // Arcs
    arc 2 13  (VARCX02_1 VARCY02_1 VARCZ02)
    arc 13 23 (VARCX02_2 VARCY02_2 VARCZ02)

    arc 6 16  (VARCX12_1 VARCY12_1 VARCZ12)
    arc 16 27 (VARCX12_2 VARCY12_2 VARCZ12)

    arc 10 19 (VARCX22_1 VARCY22_1 VARCZ22)
    arc 19 31 (VARCX22_2 VARCY22_2 VARCZ22)


    arc 3 14  (VARCX03_1 VARCY03_1 VARCZ03)
    arc 14 24 (VARCX03_2 VARCY03_2 VARCZ03)

    arc 7 17  (VARCX13_1 VARCY13_1 VARCZ13)
    arc 17 28 (VARCX13_2 VARCY13_2 VARCZ13)

    arc 11 20 (VARCX23_1 VARCY23_1 VARCZ23)
    arc 20 32 (VARCX23_2 VARCY23_2 VARCZ23)

    arc 2 6   (VARDX26 0.0 VARDZ26)
    arc 23 27 (0.0 VARDY2327 VARDZ2327)
    arc 13 16 (VARDX1316 VARDY1316 VARDZ1316)

    // Splines

    spline 3 7
    (
        (VARCBR0 0.0 VARCBZ0)
        (VARCBR1 0.0 VARCBZ1)
        (VARCBR2 0.0 VARCBZ2)
        (VARCBR3 0.0 VARCBZ3)
        (VARCBR4 0.0 VARCBZ4)
        (VARCBR5 0.0 VARCBZ5)
        (VARCBR6 0.0 VARCBZ6)
        (VARCBR7 0.0 VARCBZ7)
        (VARCBR8 0.0 VARCBZ8)
        (VARCBR9 0.0 VARCBZ9)
        (VARCBR10 0.0 VARCBZ10)
    )

    spline 14 17
    (
        (VARCBR0M VARCBR0M VARCBZ0)
        (VARCBR1M VARCBR1M VARCBZ1)
        (VARCBR2M VARCBR2M VARCBZ2)
        (VARCBR3M VARCBR3M VARCBZ3)
        (VARCBR4M VARCBR4M VARCBZ4)
        (VARCBR5M VARCBR5M VARCBZ5)
        (VARCBR6M VARCBR6M VARCBZ6)
        (VARCBR7M VARCBR7M VARCBZ7)
        (VARCBR8M VARCBR8M VARCBZ8)
        (VARCBR9M VARCBR9M VARCBZ9)
        (VARCBR10M VARCBR10M VARCBZ10)
    )

    spline 24 28
    (
        (0.0 VARCBR0 VARCBZ0)
        (0.0 VARCBR1 VARCBZ1)
        (0.0 VARCBR2 VARCBZ2)
        (0.0 VARCBR3 VARCBZ3)
        (0.0 VARCBR4 VARCBZ4)
        (0.0  VARCBR5 VARCBZ5)
        (0.0 VARCBR6 VARCBZ6)
        (0.0 VARCBR7 VARCBZ7)
        (0.0 VARCBR8 VARCBZ8)
        (0.0 VARCBR9 VARCBZ9)
        (0.0 VARCBR10 VARCBZ10)
    )
);

boundary
(
    sides
    {
        type symmetry;
        faces
        (
            (4 0 1 5)
            (5 1 2 6)
            (6 2 3 7)
            (8 4 5 9)
            (9 5 6 10)
            (10 6 7 11)

            (26 22 0 4)
            (27 23 22 26)
            (28 24 23 27)
            (30 26 4 8)
            (31 27 26 30)
            (32 28 27 31)
        );
    }

    w_core
    {
        type wall;
        faces
        (
            (30 8 9 18)
            (18 9 10 19)
            (19 10 11 20)
            (31 30 18 19)
            (32 31 19 20)
        );
    }

    symm
    {
        type symmetry;
        faces
        (
            (22 0 1 12)
            (12 1 2 13)
            (13 2 3 14)
            (23 22 12 13)
            (24 23 13 14)
        );
    }

    outlet_core
    {
        type patch;
        faces
        (
            (11 7 17 20)
            (20 17 28 32)
        );
    }

    w_blanket
    {
        type wall;
        faces
        (
            (7 3 14 17)
            (17 14 24 28)
        );
    }
);
