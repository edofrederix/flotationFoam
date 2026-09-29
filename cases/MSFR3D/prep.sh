#!/bin/bash

. ${WM_PROJECT_DIR:?}/bin/tools/RunFunctions

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

runApplication topoSet
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

m4 $VARS 0/U.helium.m4 > 0/U.helium

rm -f 0/*.m4

# helium/salt start at uniform alpha (see 0.org); real particle
# transport isn't exercised by this case, so no setLogNormal step

if [ -f heatSourceData.tar.gz ]; then
    tar xzf heatSourceData.tar.gz
    runApplication mapFields -sourceTime 0 heatSourceData
fi

runApplication decomposePar
