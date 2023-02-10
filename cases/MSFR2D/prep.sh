#!/bin/bash

source $FOAM_SRC/../bin/tools/RunFunctions
source $FOAM_SRC/../bin/tools/CleanFunctions

# Number of cells per unit length

DNDX=$1

# Width of the inlet size distribution

SIGMA=$2

# Sauter mean diameter of the inlet size distribution [m]

DSM=$3

# Mass flow rate of helium for the full reactor [kg/s]

MASSFLOWRATE=$4

# Check arguments

if [[ ! "$DNDX" =~ ^[0-9]+$ ]]; then

    echo "Invalid value set for dNdx (should be int)"
    exit 1

fi

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

TINLET=923
ALPHAHELIUMINLET=0.1
ALPHASALTINLET=0.9

DMIN=1e-10
DMAX=1e-6
NSECTIONS=16

NX1=$(echo "print(int($DNDX*(1.1275-0.0000)))" | python3)
NX2=$(echo "print(int($DNDX*(1.8275-1.1275)))" | python3)
NX3=$(echo "print(int($DNDX*(2.0645-1.8275)))" | python3)

NY1=$(echo "print(int($DNDX*(0.1875-0.0000)))" | python3)
NY2=$(echo "print(int($DNDX*(2.0675-0.1875)))" | python3)
NY3=$(echo "print(int($DNDX*(2.2550-2.0675)))" | python3)

AINLET=$(echo "print(1.8275*0.0797903731653 - 1.1275*0.0492277131293)" | python3)
RHOHELIUM=$(echo "print(2e5/($TINLET*8.314/0.004))" | python3)
JHELIUM=$(echo "print($MASSFLOWRATE/(360/5)/$RHOHELIUM/$AINLET)" | python3)
UHELIUM=$(echo "print($JHELIUM/$ALPHAHELIUMINLET)" | python3)

echo "Helium bubble distribution sigma = $SIGMA"

echo "Inlet temperature = $TINLET K"
echo "Inlet surface area = $AINLET m2"

echo "Helium mass density = $RHOHELIUM kg/m3"

echo "Helium inlet mass flow rate = $MASSFLOWRATE kg/s"
echo "Helium inlet void fraction = $ALPHAHELIUMINLET"
echo "Helium inlet superficial velocity = $JHELIUM m/s"
echo "Helium inlet velocity = $UHELIUM m/s"

cp -r 0.org 0

VARS="\
    -DVARNX1=$NX1 \
    -DVARNX2=$NX2 \
    -DVARNX3=$NX3 \
    -DVARNY1=$NY1 \
    -DVARNY2=$NY2 \
    -DVARNY3=$NY3 \
    -DVARSIGMA=$SIGMA \
    -DVARDSM=$DSM \
    -DVARTINLET=$TINLET \
    -DVARALPHAHELIUMINLET=$ALPHAHELIUMINLET \
    -DVARALPHASALTINLET=$ALPHASALTINLET \
    -DVARUHELIUM=$UHELIUM \
    -DVARDMIN=$DMIN \
    -DVARDMAX=$DMAX \
    -DVARNSECTIONS=$NSECTIONS \
    "

m4 $VARS system/blockMeshDict.m4 > system/blockMeshDict

m4 $VARS 0/lambda.helium.m4 > 0/lambda.helium
m4 $VARS 0/kappa.helium.m4 > 0/kappa.helium
m4 $VARS 0/beta.helium.m4 > 0/beta.helium

m4 $VARS 0/T.helium.m4 > 0/T.helium
m4 $VARS 0/T.salt.m4 > 0/T.salt

m4 $VARS 0/U.helium.m4 > 0/U.helium

m4 $VARS 0/alpha.helium.m4 > 0/alpha.helium
m4 $VARS 0/alpha.salt.m4 > 0/alpha.salt

m4 $VARS constant/flotationProperties.m4 > constant/flotationProperties

python3 sections.py $DMIN $DMAX $NSECTIONS $MASSFLOWRATE > log.sections.py

rm -f system/Nfs
rm -f system/Phifs
rm -f system/Ncs
rm -f constant/NcSources

for I in $(seq 1 $NSECTIONS); do

    J=$(printf '%02i' $I)

    NF=$(head -n $I sections.txt | tail -n 1)

    m4 $VARS -DVARNFNAME=Nf.$J -DVARNFPHI=phif.$J -DVARNF=$NF 0/Nf.m4 > 0/Nf.$J

    echo Nf.$J >> system/Nfs
    echo Nc.$J >> system/Ncs

    echo Phif.$J >> system/Phifs

    echo "Nc.$J {explicit 0; implicit -10;}" >> constant/NcSources

done

rm 0/*.m4

# Use the flow dictionaries. When the run is completed, the dictionaries can be
# changed with the change.sh script, to run steady state flotation

ln -s controlDict.flow system/controlDict
ln -s fvSolution.flow system/fvSolution
ln -s fvConstraints.flow system/fvConstraints

runApplication blockMesh
runApplication topoSet
runApplication setLogNormal helium $SIGMA $DSM
runApplication mapFields -sourceTime 0 heatSourceData
runApplication decomposePar
