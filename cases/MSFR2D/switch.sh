#!/bin/bash

rm -f system/controlDict system/fvSolution system/fvConstraints

ln -s controlDict.steady system/controlDict
ln -s fvSolution.steady system/fvSolution
ln -s fvConstraints.steady system/fvConstraints
