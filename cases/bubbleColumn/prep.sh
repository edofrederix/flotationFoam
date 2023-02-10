#!/bin/bash

SIGMA=0.5
DSM=4e-3
NSECTIONS=6
NF=1e7

source $FOAM_SRC/../bin/tools/RunFunctions
source $FOAM_SRC/../bin/tools/CleanFunctions

cp -r 0.org 0

VARS="\
    -DVARSIGMA=$SIGMA \
    -DVARDSM=$DSM \
    -DVARNSECTIONS=$NSECTIONS \
    -DVARNF=$NF \
    "

for I in $(seq 1 $NSECTIONS); do

    m4 $VARS -DVARNFNAME=Nf.$I -DVARNFPHI=phif.$I 0/Nf.m4 > 0/Nf.$I

done

m4 $VARS 0/kappa.air.m4 > 0/kappa.air
m4 $VARS 0/lambda.air.m4 > 0/lambda.air

rm 0/Nf.m4 0/kappa.air.m4 0/lambda.air.m4

runApplication blockMesh

runApplication setLogNormal air $SIGMA $DSM
