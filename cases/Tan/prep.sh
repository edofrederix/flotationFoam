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

. ${WM_PROJECT_DIR:?}/bin/tools/RunFunctions

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
    "

m4 $VARS system/blockMeshDict.m4 > system/blockMeshDict
m4 $VARS system/topoSetDict.m4 > system/topoSetDict
m4 $VARS system/setFieldsDict.m4 > system/setFieldsDict

runApplication blockMesh
runApplication topoSet
runApplication setFields
runApplication decomposePar
