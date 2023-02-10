#!/bin/bash

source $FOAM_SRC/../bin/tools/RunFunctions
source $FOAM_SRC/../bin/tools/CleanFunctions

cleanCase

rm -rf \
    0 \
    system/blockMeshDict \
    sections.txt \
    system/Nfs \
    system/Ncs \
    system/Phifs \
    constant/NcSources \
    system/fvSolution \
    system/fvConstraints \
    system/controlDict \
    constant/flotationProperties
