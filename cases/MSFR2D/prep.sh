#!/bin/bash

source $FOAM_SRC/../bin/tools/RunFunctions
source $FOAM_SRC/../bin/tools/CleanFunctions

# Width of the inlet size distribution

SIGMA=${1:-0.5}

# Sauter mean diameter of the inlet size distribution [m]

DSM=${2:-1e-3}

# Mass flow rate of helium for the full reactor [kg/s]

MASSFLOWRATE=${3:-0.01}

# Number of cells per unit length

DNDX=${4:-16}

# Check arguments

if [[ ! "$SIGMA" =~ [0-9]+(\.[0-9]+?)?$ ]]; then

    echo "Invalid value set for sigma (should be float)"
    exit 1

fi

if [[ ! "$DSM" =~ [0-9]+(\.[0-9]+?)?$ ]]; then

    echo "Invalid value set for dsm (should be float)"
    exit 1

fi

if [[ ! "$MASSFLOWRATE" =~ [0-9]+(\.[0-9]+?)?$ ]]; then

    echo "Invalid value set for helium mass flow rate (should be float)"
    exit 1

fi

if [[ ! "$DNDX" =~ ^[0-9]+$ ]]; then

    echo "Invalid value set for dNdx (should be int)"
    exit 1

fi

NX1=$(echo "print(int($DNDX*(1.1275-0.0000)))" | python3)
NX2=$(echo "print(int($DNDX*(1.8275-1.1275)))" | python3)
NX3=$(echo "print(int($DNDX*(2.0645-1.8275)))" | python3)

NY1=$(echo "print(int($DNDX*(0.1875-0.0000)))" | python3)
NY2=$(echo "print(int($DNDX*(2.0675-0.1875)))" | python3)
NY3=$(echo "print(int($DNDX*(2.2550-2.0675)))" | python3)
NY4=$(echo "print(int($DNDX*(2.0675-1.2275)))" | python3)

MASSFLOWRATEQ=$(echo "print($MASSFLOWRATE/(360.0/5.0))" | python3)

cp -r 0.org 0

VARS="\
    -DVARNX1=$NX1 \
    -DVARNX2=$NX2 \
    -DVARNX3=$NX3 \
    -DVARNY1=$NY1 \
    -DVARNY2=$NY2 \
    -DVARNY3=$NY3 \
    -DVARNY4=$NY4 \
    -DVARSIGMA=$SIGMA \
    -DVARDSM=$DSM \
    -DVARMASSFLOWRATEQ=$MASSFLOWRATEQ \
    "

m4 $VARS system/blockMeshDict.m4 > system/blockMeshDict

m4 $VARS 0/lambda.helium.m4 > 0/lambda.helium
m4 $VARS 0/kappai.helium.m4 > 0/kappai.helium

m4 $VARS 0/U.helium.m4 > 0/U.helium

rm 0/*.m4

runApplication blockMesh

runApplication createZones
runApplication setLogNormal helium $SIGMA $DSM

tar xzf heatSourceData.tar.gz
runApplication mapFields -sourceTime 0 heatSourceData

runApplication decomposePar
