#!/bin/bash

DSM=${1:-1e-2}
SIGMA=${2:-0.5}
NSECTIONS=${3:-6}
NF=${4:-1e7}

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

m4 $VARS 0/kappai.air.m4 > 0/kappai.air
m4 $VARS 0/lambda.air.m4 > 0/lambda.air

rm -f 0/*.m4

runApplication blockMesh

runApplication setLogNormal air $SIGMA $DSM
