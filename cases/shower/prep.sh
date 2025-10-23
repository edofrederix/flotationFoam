#!/bin/bash

source $FOAM_SRC/../bin/tools/RunFunctions
source $FOAM_SRC/../bin/tools/CleanFunctions

MESH=${1:-32}       # Number of cells per unit length (defaults to 32)

R=0.75              # Radius of the conical floor [m]
RV=1.5              # Radius of the vessel [m]
RC=0.125            # Radius of the cone [m]

HC=2.75             # Height of the cone [m]
HI=3.0              # Heigh of the inlet [m]
HS=0.25             # Depth of the sink [m]
HO=0.1              # Height of an additional layer on top of the floor [m]

G=3.0               # Grading towards the vessel wall [-]

SLOPE_CONE=45.0     # Slope of the cone [deg]
SLOPE_FLOOR=15.0    # Slope of the floor [deg]

ASPECT_RATIO=3      # Cell aspect ratio [-]

DSM=1e-3            # Inlet/initial Sauter mean diameter [m]
SIGMA=0.5           # Inlet/initial size distribution width [-]

##

RSQRT2=$(python -c "import math as m; print($R/m.sqrt(2))")
RCSQRT2=$(python -c "import math as m; print($RC/m.sqrt(2))")
RVSQRT2=$(python -c "import math as m; print($RV/m.sqrt(2))")

S=$(python -c "import math as m; print($R*0.6)")
SC=$(python -c "import math as m; print($RC*0.5)")

ALPHA=$(python -c "import math as m; print(m.atan($RCSQRT2/$S))")

FAC=0.8
S_MOD=$(python -c "import math as m; print($S*$FAC)")
SC_MOD=$(python -c "import math as m; print($SC*$FAC)")

X10=$(python -c "import math as m; print(m.cos($ALPHA)*$R)")
Y10=$(python -c "import math as m; print(m.sin($ALPHA)*$R)")

X75=$(python -c "import math as m; print(m.cos($ALPHA)*$RV)")
Y75=$(python -c "import math as m; print(m.sin($ALPHA)*$RV)")

HCPLUS=$(python -c "import math as m; print($HC+1e-6)")

THETA=$(python -c "import math as m; print(m.asin($RCSQRT2/$R)*360.0/(2.0*m.pi))")
GAMMA=$(python -c "import math as m; print(45.0-$THETA)")

NSC=$(python -c "import math as m; print(int(max(round($RCSQRT2*$MESH),1)))")
NRC=$(python -c "import math as m; print(int(max(round(($RC-$SC)*$MESH),1)))")
NS=$(python -c "import math as m; print(int(max(round(($S-$RC)*$MESH),1)))")
NR=$(python -c "import math as m; print(int(max(round(($R-$S)*$MESH),1)))")

Q=$(echo "import math as m; print((($RV-$R)-$G/$MESH)/(($RV-$R)-1.0/$MESH))" | python)
NRV=$(echo "import math as m; print(int(max(round(m.log(1.0/$G)/m.log($Q)+1),1)))" | python)

NHO=$(python -c "import math as m; print(int(max(round($HO*$MESH/$ASPECT_RATIO),1)))")
NHC=$(python -c "import math as m; print(int(max(round(($HC - $HO)*$MESH/$ASPECT_RATIO),1)))")
NHI=$(python -c "import math as m; print(int(max(round(($HI - $HC)*$MESH/$ASPECT_RATIO),1)))")
NHS=$(python -c "import math as m; print(int(max(round($HS*$MESH/$ASPECT_RATIO),1)))")

m4  -DVARR=$R -DVARRC=$RC -DVARRV=$RV \
    -DVARHC=$HC -DVARHI=$HI -DVARHO=$HO -DVARHS=$HS \
    -DVARRSQRT2=$RSQRT2 -DVARRCSQRT2=$RCSQRT2 -DVARRVSQRT2=$RVSQRT2\
    -DVARS=$S -DVARSC=$SC \
    -DVARS_MOD=$S_MOD -DVARSC_MOD=$SC_MOD \
    -DVARX10=$X10 -DVARX75=$X75 \
    -DVARY10=$Y10 -DVARY75=$Y75 \
    -DVARHCPLUS=$HCPLUS \
    -DVARTHETA=$THETA -DVARGAMMA=$GAMMA \
    -DVARNSC=$NSC -DVARNRC=$NRC -DVARNS=$NS -DVARNR=$NR -DVARNRV=$NRV \
    -DVARNHO=$NHO -DVARNHC=$NHC -DVARNHI=$NHI -DVARNHS=$NHS \
    -DVARG=$G \
        system/blockMeshDict.m4 > system/blockMeshDict

cp -r 0.org 0

runApplication blockMesh
runApplication createPatch

wmake -s makeCones
runApplication ./makeCones/makeCones $RC $R $SLOPE_CONE $SLOPE_FLOOR $HC $HI $HS

m4 -DVARDSM=$DSM -DVARSIGMA=$SIGMA 0/lambda.salt.m4 > 0/lambda.salt
m4 -DVARDSM=$DSM -DVARSIGMA=$SIGMA 0/kappai.salt.m4 > 0/kappai.salt

rm -f 0/*.m4

runApplication setLogNormal salt $SIGMA $DSM
