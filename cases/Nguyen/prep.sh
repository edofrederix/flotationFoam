#!/bin/bash

SIGMA=0.187353
DSM=0.00016374

A=0.01
B=0.024748
R=0.035
C=0.012
H=0.35
HL=0.3
HF=0.3

NA=10
NB=12
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
m4 $VARS system/topoSetDict.m4 > system/topoSetDict
m4 $VARS system/setFieldsDict.m4 > system/setFieldsDict

rm -f system/Nfs system/Ncs system/NcConstraints system/NfFiedValues

for I in $(seq 1 $NSECTIONS); do

    J=$(printf '%02i' $I)

    m4 $VARS -DVARNFNAME=Nf.$J -DVARNFPHI=phif.$J 0/Nf.m4 > 0/Nf.$J

    echo Nf.$J >> system/Nfs
    echo Nc.$J >> system/Ncs
    echo "Nc.$J 0;" >> system/NcConstraints
    echo "volScalarFieldValue Nf.$J $NF" >> system/NfFieldValues

done

m4 $VARS 0/kappa.nitrogen.m4 > 0/kappa.nitrogen
m4 $VARS 0/lambda.nitrogen.m4 > 0/lambda.nitrogen

rm 0/Nf.m4 0/kappa.nitrogen.m4 0/lambda.nitrogen.m4

runApplication blockMesh

runApplication topoSet
runApplication setFields
runApplication setLogNormal nitrogen $SIGMA $DSM
