#!/bin/bash

source $FOAM_SRC/../bin/tools/CleanFunctions

rm -fr output-*
rm -f log.* mesh

cd core
rm -f system/blockMeshDict
cleanCase
cd ..

cd pump
rm -f system/blockMeshDict
cleanCase
cd ..
