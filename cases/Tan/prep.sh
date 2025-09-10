#!/bin/bash

DSM=1e-3
SIGMA=0.2

A=0.00171
B=0.00424
R=0.006
C=0.00206
H=0.3
HL=0.26
HF=0.26

NA=5
NB=6
NH=100

NSECTIONS=16

NF=1e6

source $FOAM_SRC/../bin/tools/RunFunctions
source $FOAM_SRC/../bin/tools/CleanFunctions

cp -r 0.org 0

VARS="\
    -DVARSIGMA=$SIGMA \
    -DVARDSM=$DSM \
    -DVARA=$A \
    -DVARB=$B \
    -DVARR=$R \
    -DVARC=$C \
    -DVARH=$H \
    -DVARHL=$HL \
    -DVARHF=$HF \
    -DVARNA=$NA \
    -DVARNB=$NB \
    -DVARNH=$NH \
    -DVARNF=$NF \
    "

m4 $VARS system/blockMeshDict.m4 > system/blockMeshDict
m4 $VARS system/createZonesDict.m4 > system/createZonesDict
m4 $VARS system/setFieldsDict.m4 > system/setFieldsDict

rm -f system/Nfs system/Ncs system/NcConstraints system/NfFiedValues

for I in $(seq 1 $NSECTIONS); do

    J=$(printf '%02i' $I)

    m4 $VARS -DVARNFNAME=N.water:$J -DVARNFPHI=phi.water:$J 0/N.water.m4 > 0/N.water:$J

    echo N.water:$J >> system/Nfs
    echo N.nitrogen:$J >> system/Ncs
    echo "N.nitrogen:$J 0;" >> system/NcConstraints
    echo "N.water:$J $NF;" >> system/NfFieldValues

done

m4 $VARS 0/kappai.nitrogen.m4 > 0/kappai.nitrogen
m4 $VARS 0/lambda.nitrogen.m4 > 0/lambda.nitrogen

rm -f 0/*.m4

runApplication blockMesh

runApplication createZones
runApplication setFields
runApplication setLogNormal nitrogen $SIGMA $DSM
runApplication decomposePar
