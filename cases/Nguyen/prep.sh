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
