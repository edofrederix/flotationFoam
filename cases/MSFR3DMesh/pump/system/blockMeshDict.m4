FoamFile
{
    format      ascii;
    class       dictionary;
    object      blockMeshDict;
}

convertToMeters 1;

vertices
(
    (VARPX2 -VARPY5 VARPZ0)   // 0
    (VARPX3 -VARPY5 VARPZ0)
    (VARPX4 -VARPY5 VARPZ0)

    (VARPX2 -VARPY5 VARPZ1)   // 3
    (VARPX3 -VARPY5 VARPZ1)
    (VARPX4 -VARPY5 VARPZ1)


    (VARPX2 -VARPY2 VARPZ0)   // 6
    (VARPX3 -VARPY1 VARPZ0)
    (VARPX4 -VARPY1 VARPZ0)

    (VARPX2 -VARPY2 VARPZ1)   // 9
    (VARPX3 -VARPY1 VARPZ1)
    (VARPX4 -VARPY1 VARPZ1)

    (VARPX2 -VARPY2 VARPZ2)   // 12
    (VARPX3 -VARPY1 VARPZ2)

    (VARCOSPR0 -VARSINPR0 VARPZ3) // 14
    (VARCOSPR1 -VARPY3 VARPZ4)

    (VARCOSPR0 -VARSINPR0 VARPZ5) // 16
    (VARCOSPR1 -VARPY3 VARPZ6)


    (VARPX2 VARPY2 VARPZ0)   // 18
    (VARPX3 VARPY1 VARPZ0)
    (VARPX4 VARPY1 VARPZ0)

    (VARPX2 VARPY2 VARPZ1)   // 21
    (VARPX3 VARPY1 VARPZ1)
    (VARPX4 VARPY1 VARPZ1)

    (VARPX2 VARPY2 VARPZ2)   // 24
    (VARPX3 VARPY1 VARPZ2)

    (VARCOSPR0 VARSINPR0 VARPZ3) // 26
    (VARCOSPR1 VARPY3 VARPZ4)

    (VARCOSPR0 VARSINPR0 VARPZ5) // 28
    (VARCOSPR1 VARPY3 VARPZ6)


    (VARPX2 VARPY5 VARPZ0)   // 30
    (VARPX3 VARPY5 VARPZ0)
    (VARPX4 VARPY5 VARPZ0)

    (VARPX2 VARPY5 VARPZ1)   // 33
    (VARPX3 VARPY5 VARPZ1)
    (VARPX4 VARPY5 VARPZ1)
);

blocks
(
    hex (0 1 7 6 3 4 10 9) (VARPNX1 VARPNY1 VARPNZ0) simpleGrading (1 1 1)
    hex (1 2  8 7 4 5 11 10) (VARPNX2 VARPNY1 VARPNZ0) simpleGrading (1 1 1)
    hex (6 7 19 18 9 10 22 21) (VARPNX1 VARPNY0 VARPNZ0) simpleGrading (1 1 1)
    hex (7 8 20 19 10 11 23 22) (VARPNX2 VARPNY0 VARPNZ0) simpleGrading (1 1 1)
    hex (18 19 31 30 21 22 34 33) (VARPNX1 VARPNY1 VARPNZ0) simpleGrading (1 1 1)
    hex (19 20 32 31 22 23 35 34)  (VARPNX2 VARPNY1 VARPNZ0) simpleGrading (1 1 1)

    hex (9 10 22 21 12 13 25 24) (VARCNZ1 VARPNY0 VARPNZ1) simpleGrading (1 1 1)
    hex (12 13 25 24 15 17 29 27) (VARCNZ1 VARPNY0 VARPNB) simpleGrading (1 1 1)
    hex (14 15 27 26 16 17 29 28) (VARPNX0 VARPNY0 VARCNZ1) simpleGrading (1 1 1)
);

edges
(
    arc 14 26 (VARPR0 0 VARPZ3)
    arc 16 28 (VARPR0 0 VARPZ5)

    arc 15 27 (VARPR1 0 VARPZ4)
    arc 17 29 (VARPR1 0 VARPZ6)

    spline 14 15 ((VARPPR0 -VARPPY0 VARPPZ0) (VARPPR1 -VARPPY1 VARPPZ1) (VARPPR2 -VARPPY2 VARPPZ2) (VARPPR3 -VARPPY3 VARPPZ3) (VARPPR4 -VARPPY4 VARPPZ4))
    spline 26 27 ((VARPPR0 VARPPY0 VARPPZ0) (VARPPR1 VARPPY1 VARPPZ1) (VARPPR2 VARPPY2 VARPPZ2) (VARPPR3 VARPPY3 VARPPZ3) (VARPPR4 VARPPY4 VARPPZ4))

    arc 15 12 (VARPAX0 -VARPAY0 VARPAZ0)
    arc 27 24 (VARPAX0 VARPAY0 VARPAZ0)

    arc 17 13 (VARPAX1 -VARPAY1 VARPAZ1)
    arc 29 25 (VARPAX1 VARPAY1 VARPAZ1)
);

boundary
(
    inlet_pump
    {
        type patch;
        faces
        (
            (28 26 14 16)
        );
    }
    w_pipes
    {
        type wall;
        faces
        (
            (16 14 15 17)
            (15 12 13 17)
            (26 28 29 27)
            (27 29 25 24)
            (28 16 17 29)
            (14 26 27 15)
            (29 17 13 25)
            (15 27 24 12)

            (12 9 10 13)
            (21 24 25 22)
            (24 21 9 12)
            (13 10 22 25)
        );
    }

    w_pump
    {
        type wall;
        faces
        (
            (3 0 1 4)
            (4 1 2 5)
            (35 32 31 34)
            (34 31 30 33)

            (3 9 6 0)
            (9 21 18 6)
            (21 33 30 18)

            (5 2 8 11)
            (11 8 20 23)
            (23 20 32 35)

            (9 3 4 10)
            (10 4 5 11)
            (22 10 11 23)
            (33 21 22 34)
            (34 22 23 35)
        );
    }

    outlet
    {
        type patch;
        faces
        (
            (0 6 7 1)
            (6 18 19 7)
            (18 30 31 19)
            (1 7 8 2)
            (7 19 20 8)
            (19 31 32 20)
        );
    }
);
