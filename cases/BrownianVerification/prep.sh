#!/bin/bash

SIGMA=0.5
DSM=4e-3
NSECTIONS=12
NF=1e6

source $FOAM_SRC/../bin/tools/RunFunctions
source $FOAM_SRC/../bin/tools/CleanFunctions

cp -r 0.org 0

VARS="\
    -DVARSIGMA=$SIGMA \
    -DVARDSM=$DSM \
    -DVARNSECTIONS=$NSECTIONS \
    -DVARNF=$NF \
    "

rm -f system/Nfs system/Ncs

for I in $(seq 1 $NSECTIONS); do

    J=$(printf '%02i' $I)

    m4 $VARS -DVARNFNAME=Nf.$J -DVARNFPHI=phif.$J 0/Nf.m4 > 0/Nf.$J

    echo Nf.$J >> system/Nfs
    echo Nc.$J >> system/Ncs

done

m4 $VARS 0/kappa.air.m4 > 0/kappa.air
m4 $VARS 0/lambda.air.m4 > 0/lambda.air

rm 0/Nf.m4 0/kappa.air.m4 0/lambda.air.m4

runApplication blockMesh

runApplication setLogNormal air $SIGMA $DSM
