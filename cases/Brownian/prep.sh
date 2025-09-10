#!/bin/bash

DSM=${1:-4e-3}
SIGMA=${2:-0.5}
NSECTIONS=${3:-12}
NF=${4:-1e6}

source $FOAM_SRC/../bin/tools/RunFunctions
source $FOAM_SRC/../bin/tools/CleanFunctions

cp -r 0.org 0

VARS="\
    -DVARSIGMA=$SIGMA \
    -DVARDSM=$DSM \
    -DVARNSECTIONS=$NSECTIONS \
    -DVARNF=$NF \
    "

rm -f system/fields

for I in $(seq 1 $NSECTIONS); do

    J=$(printf '%02i' $I)

    m4 $VARS -DVARNFNAME=N.water:$J -DVARNFPHI=phi.water:$J 0/N.water.m4 > 0/N.water:$J

    echo N.water:$J >> system/fields
    echo N.air:$J >> system/fields

done

m4 $VARS 0/kappai.air.m4 > 0/kappai.air
m4 $VARS 0/lambda.air.m4 > 0/lambda.air

rm 0/*.m4

runApplication blockMesh

runApplication setLogNormal air $SIGMA $DSM
