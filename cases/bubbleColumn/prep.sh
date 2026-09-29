#!/bin/bash

. ${WM_PROJECT_DIR:?}/bin/tools/RunFunctions

cp -r 0.org 0

runApplication blockMesh
runApplication setFields
runApplication decomposePar
