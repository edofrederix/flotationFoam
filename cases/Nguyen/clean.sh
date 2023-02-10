#!/bin/bash

source $FOAM_SRC/../bin/tools/RunFunctions
source $FOAM_SRC/../bin/tools/CleanFunctions

cleanCase

rm -rf \
    0 \
    system/Ncs system/Nfs \
    system/NcConstraints \
    system/NfFieldValues \
    *.pdf \
    *.png \
    __pycache__ \
    log.* \
    system/blockMeshDict \
    system/topoSetDict \
    system/setFieldsDict
