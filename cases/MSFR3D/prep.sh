#!/bin/bash

source $FOAM_SRC/../bin/tools/RunFunctions
source $FOAM_SRC/../bin/tools/CleanFunctions

# Width of the inlet size distribution

SIGMA=${1:-0.5}

# Sauter mean diameter of the inlet size distribution [m]

DSM=${2:-1e-3}

# Mass flow rate of helium for the full reactor [kg/s]

MASSFLOWRATE=${3:-0.01}

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

# Prepare the mesh

tar xzf mesh.tar.gz -C constant/

runApplication createZones
runApplication createPatch

# Create mapped inlet BC

runApplication -append foamDictionary constant/polyMesh/boundary -entry entry0/inlet/type -set mappedInternal
runApplication -append foamDictionary constant/polyMesh/boundary -entry entry0/inlet/inGroups -set 'List<word> 1(mappedInternal)'
runApplication -append foamDictionary constant/polyMesh/boundary -entry entry0/inlet/offsetMode -set direction
runApplication -append foamDictionary constant/polyMesh/boundary -entry entry0/inlet/offset -set '(0 0 0.2)'

# Prepare boundary conditions

MASSFLOWRATEQ=$(echo "print($MASSFLOWRATE/4.0)" | python3)

cp -r 0.org 0

VARS="\
    -DVARSIGMA=$SIGMA \
    -DVARDSM=$DSM \
    -DVARMASSFLOWRATEQ=$MASSFLOWRATEQ \
    "

m4 $VARS 0/lambda.helium.m4 > 0/lambda.helium
m4 $VARS 0/kappai.helium.m4 > 0/kappai.helium

m4 $VARS 0/U.helium.m4 > 0/U.helium

rm -f 0/*.m4

runApplication setLogNormal helium $SIGMA $DSM

tar xzf heatSourceData.tar.gz
runApplication mapFields -sourceTime 0 heatSourceData

runApplication decomposePar
