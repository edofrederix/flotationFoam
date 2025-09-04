#!/bin/bash

source $FOAM_SRC/../bin/tools/RunFunctions
source $FOAM_SRC/../bin/tools/CleanFunctions

cleanCase
rm -rf 0 system/fields *.pdf *.png __pycache__ log.*
