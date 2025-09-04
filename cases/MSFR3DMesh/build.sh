#!/bin/bash

source $FOAM_SRC/../bin/tools/RunFunctions

MESH=$1

if [[ ! "$MESH" =~ ^[0-9]+$ ]]; then

    echo "Invalid number of cells per unit length (should be int)"
    exit 1

fi

CASE=output-$MESH
rm -fr $CASE

# Use OpenFOAM 11. Commented commands are for OpenFOAM-13, but this is currently
# giving problems. There seems to be a bug in stitchMesh.

module switch OpenFOAM/11

# Prepare core

./setVariables.sh $MESH core/system/blockMeshDict.m4 > core/system/blockMeshDict
runApplication -overwrite -suffix core blockMesh -case core
runApplication -overwrite -suffix core createZones -case core

# Prepare pump

./setVariables.sh $MESH pump/system/blockMeshDict.m4 > pump/system/blockMeshDict
runApplication -overwrite -suffix pump blockMesh -case pump

# Start with core

cp -r core $CASE

# Rotate pump by 90/8 degrees

runApplication -suffix 0 -overwrite rotateMesh -constant -case pump '(1 0 0)' '(0.9807852804032304 0.19509032201612825 0)'
#runApplication -suffix 0 -overwrite transformPoints -case pump rotate="((1 0 0) (0.9807852804032304 0.19509032201612825 0))"

for I in $(seq 1 4); do

    # Merge pump

    runApplication -suffix $I -overwrite mergeMeshes -overwrite $CASE pump
    # runApplication -suffix $I -overwrite mergeMeshes -case $CASE -addCases "(\"pump\")"

    # Rotate pump by 90/4 degrees

    runApplication -suffix $I -overwrite rotateMesh -constant -case pump '(1 0 0)' '(0.9238795325112867 0.3826834323650898 0)'
    # runApplication -suffix $I -overwrite transformPoints -case pump rotate="((1 0 0) (0.9238795325112867 0.3826834323650898 0))"

done

# Stitch

runApplication -suffix 1 -overwrite stitchMesh -case $CASE -overwrite outlet_core inlet_pump
# runApplication -suffix 1 -overwrite stitchMesh -case $CASE "((outlet_core inlet_pump))"

# Mirror mesh

rm -fr $CASE-mirror
cp -r $CASE $CASE-mirror

runApplication -suffix m1 -overwrite rotateMesh -constant -case $CASE-mirror '(0 0 1)' '(0 0 -1)'
runApplication -suffix m1 -overwrite rotateMesh -constant -case $CASE-mirror '(0 1 0)' '(1 0 0)'
# runApplication -suffix m1 -overwrite transformPoints -case $CASE-mirror rotate="((0 0 1) (0 0 -1))"
# runApplication -suffix m1 -overwrite transformPoints -case $CASE-mirror rotate="((0 1 0) (1 0 0))"

# Rename symm and outlet patch

sed -i 's/symm$/symm_mirror/g' $CASE-mirror/constant/polyMesh/boundary
sed -i 's/outlet$/inlet/g' $CASE-mirror/constant/polyMesh/boundary

# Merge

runApplication -suffix m1 -overwrite mergeMeshes -overwrite $CASE $CASE-mirror
# runApplication -suffix m1 -overwrite mergeMeshes -case $CASE -addCases "(\"$CASE-mirror\")"

rm -fr $CASE-mirror

# Stitch

runApplication -suffix 1 -overwrite stitchMesh -case $CASE -overwrite symm symm_mirror
# runApplication -suffix 2 -overwrite stitchMesh -case $CASE "((symm symm_mirror))"

# Remove empty patches

foamDictionary -entry entry0/outlet_core -remove $CASE/constant/polyMesh/boundary
foamDictionary -entry entry0/inlet_pump -remove $CASE/constant/polyMesh/boundary
foamDictionary -entry entry0/symm -remove $CASE/constant/polyMesh/boundary
foamDictionary -entry entry0/symm_mirror -remove $CASE/constant/polyMesh/boundary

# Switch back to OpenFOAM 13

module switch OpenFOAM/13

# Make package

cp -r $CASE/constant/polyMesh .
rm -f mesh-$MESH.tar.gz
tar czf mesh-$MESH.tar.gz polyMesh
rm -r polyMesh
