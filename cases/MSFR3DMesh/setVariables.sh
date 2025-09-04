MESH=$1

if [[ ! "$MESH" =~ ^[0-9]+$ ]]; then

    echo "Invalid number of cells per unit length (should be int)"
    exit 1

fi

FILE=$2

# Core variables

SQRT2="1.4142135623730951"

CR00="0.0"
CR01="0.56"
CR02="0.83"
CR03="1.0567102733001132"

CR10="0.0"
CR11="0.72"
CR12="1.08"
CR13="$SQRT2"

CR20="0.0"
CR21="0.75"
CR22="1.1"
CR23="$SQRT2"

ALPHAROOF="13"

CZ00="0.0"
CZ10="0.6"
CZ20="0.801352"

CZ01="0.0"
CZ11="0.75"
CZ21=$(python -c "import math as m; print($CZ20 + m.tan($ALPHAROOF/360*2*m.pi) * $CR21)")

CZ02="0.0"
CZ12="0.84"
CZ22=$(python -c "import math as m; print($CZ20 + m.tan($ALPHAROOF/360*2*m.pi) * $CR22)")

CZ03="0.0"
CZ13="0.9475"
CZ23=$(python -c "import math as m; print($CZ20 + m.tan($ALPHAROOF/360*2*m.pi) * $CR23)")

CBZ10="0.874099"
CBZ9="0.783131"
CBZ8="0.69609"
CBZ7="0.603438"
CBZ6="0.521193"
CBZ5="0.440278"
CBZ4="0.358338"
CBZ3="0.27915"
CBZ2="0.204974"
CBZ1="0.125892"
CBZ0="0.0566774"

CBR10="1.33518"
CBR9="1.26888"
CBR8="1.22081"
CBR7="1.1795"
CBR6="1.14849"
CBR5="1.12262"
CBR4="1.10095"
CBR3="1.08424"
CBR2="1.0723"
CBR1="1.06349"
CBR0="1.059"

CNR0=$(python -c "print(int(round(($CR21 - $CR20)*$MESH /2.0))*2)")
CNR1=$(python -c "print(int(round(0.95*($CR22 - $CR21)*$MESH)))")
CNR2=$(python -c "print(int(round(0.9*($CR23 - $CR22)*$MESH)))")

CNZ0=$(python -c "print(int(round(($CZ10 - $CZ00)*$MESH)))")
CNZ1=$(python -c "print(int(round(($CZ20 - $CZ10)*$MESH)))")

# Pump variables

ALPHA0="11.25"
ALPHA1="7.4"

PXX0="1.38388"
PXX1="2.0245"

PYY0="0.27527"
PYY1="0.11964"

PX2="1.78522"
PX3="2.0245"
PX4="2.18849"

PR0="$CR13"
PR1="1.69715"

PZ0="0.1"
PZ1="0.834708"
PZ2="0.974708"
PZ3="$CZ13"
PZ4="1.05566"
PZ5="$CZ23"
PZ6="1.23641"

PY1="0.11964"
PY2=$(python -c "print($PYY0 - ($PYY0 - $PYY1) * ($PX2-$PXX0) / ($PXX1-$PXX0))")
PY3=$(python -c "print($PYY0 - ($PYY0 - $PYY1) * ($PR1-$PXX0) / ($PXX1-$PXX0))")
PY4="$PYY0"
PY5="0.337769"

PPR0="1.46671"
PPR1="1.51813"
PPR2="1.56275"
PPR3="1.60788"
PPR4="1.65321"

PPZ0="0.982627"
PPZ1="1.00576"
PPZ2="1.02159"
PPZ3="1.03526"
PPZ4="1.0479"

PPY0=$(python -c "print($PYY0 - ($PYY0 - $PYY1) * ($PPR0-$PXX0) / ($PXX1-$PXX0))")
PPY1=$(python -c "print($PYY0 - ($PYY0 - $PYY1) * ($PPR1-$PXX0) / ($PXX1-$PXX0))")
PPY2=$(python -c "print($PYY0 - ($PYY0 - $PYY1) * ($PPR2-$PXX0) / ($PXX1-$PXX0))")
PPY3=$(python -c "print($PYY0 - ($PYY0 - $PYY1) * ($PPR3-$PXX0) / ($PXX1-$PXX0))")
PPY4=$(python -c "print($PYY0 - ($PYY0 - $PYY1) * ($PPR4-$PXX0) / ($PXX1-$PXX0))")

PAX0="1.75726"
PAX1="1.9294"

PAY0=$(python -c "print($PYY0 - ($PYY0 - $PYY1) * ($PAX0-$PXX0) / ($PXX1-$PXX0))")
PAY1=$(python -c "print($PYY0 - ($PYY0 - $PYY1) * ($PAX1-$PXX0) / ($PXX1-$PXX0))")

PAZ0="1.03171"
PAZ1="1.16036"

PNX0=$(python -c "print(int(round(0.8*($PR1-$PR0)*$MESH)))")
PNX1="$CNZ1"
PNX2=$(python -c "print(int(round(($PX4-$PX3)*$MESH)))")

PNY0=$(python -c "print(int(round($CNR0 /2.0)))")
PNY1=$(python -c "print(int(round(($PY5-$PY2)*$MESH)))")

PNZ0=$(python -c "print(int(round(($PZ1-$PZ0)*$MESH)))")
PNZ1=$(python -c "print(int(round(($PZ2-$PZ1)*$MESH)))")

PNB=$(python -c "print(int(round(0.9*($PX3-$PR1)*$MESH)))")

##

FC=1.1;

CR01M=$(python -c "print($CR01 / $SQRT2 * $FC)")
CR02M=$(python -c "print($CR02 / $SQRT2)")
CR03M=$(python -c "print($CR03 / $SQRT2)")
CR11M=$(python -c "print($CR11 / $SQRT2 * $FC)")
CR12M=$(python -c "print($CR12 / $SQRT2)")
CR13M=$(python -c "print($CR13 / $SQRT2)")
CR21M=$(python -c "print($CR21 / $SQRT2 * $FC)")
CR22M=$(python -c "print($CR22 / $SQRT2)")
CR23M=$(python -c "print($CR23 / $SQRT2)")

CZ01M=$CZ01
CZ02M=$CZ02
CZ03M=$CZ03
CZ11M=$CZ11
CZ12M=$CZ12
CZ13M=$CZ13
CZ21M=$(python -c "import math as m; print(m.sqrt(2.0*($CR21M)**2)/$CR21*($CZ21-$CZ20)*$FC+$CZ20)")
CZ22M=$CZ22
CZ23M=$CZ23

CBR0M=$(python -c "print($CBR0 / $SQRT2)")
CBR1M=$(python -c "print($CBR1 / $SQRT2)")
CBR2M=$(python -c "print($CBR2 / $SQRT2)")
CBR3M=$(python -c "print($CBR3 / $SQRT2)")
CBR4M=$(python -c "print($CBR4 / $SQRT2)")
CBR5M=$(python -c "print($CBR5 / $SQRT2)")
CBR6M=$(python -c "print($CBR6 / $SQRT2)")
CBR7M=$(python -c "print($CBR7 / $SQRT2)")
CBR8M=$(python -c "print($CBR8 / $SQRT2)")
CBR9M=$(python -c "print($CBR9 / $SQRT2)")
CBR10M=$(python -c "print($CBR10 / $SQRT2)")

CX02_1=$(python -c "import math as m; print($CR02*m.cos(22.5/360.0*2*m.pi))")
CX02_2=$(python -c "import math as m; print($CR02*m.cos(67.5/360.0*2*m.pi))")
CY02_1=$(python -c "import math as m; print($CR02*m.sin(22.5/360.0*2*m.pi))")
CY02_2=$(python -c "import math as m; print($CR02*m.sin(67.5/360.0*2*m.pi))")
CX12_1=$(python -c "import math as m; print($CR12*m.cos(22.5/360.0*2*m.pi))")
CX12_2=$(python -c "import math as m; print($CR12*m.cos(67.5/360.0*2*m.pi))")
CY12_1=$(python -c "import math as m; print($CR12*m.sin(22.5/360.0*2*m.pi))")
CY12_2=$(python -c "import math as m; print($CR12*m.sin(67.5/360.0*2*m.pi))")
CX22_1=$(python -c "import math as m; print($CR22*m.cos(22.5/360.0*2*m.pi))")
CX22_2=$(python -c "import math as m; print($CR22*m.cos(67.5/360.0*2*m.pi))")
CY22_1=$(python -c "import math as m; print($CR22*m.sin(22.5/360.0*2*m.pi))")
CY22_2=$(python -c "import math as m; print($CR22*m.sin(67.5/360.0*2*m.pi))")
CX03_1=$(python -c "import math as m; print($CR03*m.cos(22.5/360.0*2*m.pi))")
CX03_2=$(python -c "import math as m; print($CR03*m.cos(67.5/360.0*2*m.pi))")
CY03_1=$(python -c "import math as m; print($CR03*m.sin(22.5/360.0*2*m.pi))")
CY03_2=$(python -c "import math as m; print($CR03*m.sin(67.5/360.0*2*m.pi))")
CX13_1=$(python -c "import math as m; print($CR13*m.cos(22.5/360.0*2*m.pi))")
CX13_2=$(python -c "import math as m; print($CR13*m.cos(67.5/360.0*2*m.pi))")
CY13_1=$(python -c "import math as m; print($CR13*m.sin(22.5/360.0*2*m.pi))")
CY13_2=$(python -c "import math as m; print($CR13*m.sin(67.5/360.0*2*m.pi))")
CX23_1=$(python -c "import math as m; print($CR23*m.cos(22.5/360.0*2*m.pi))")
CX23_2=$(python -c "import math as m; print($CR23*m.cos(67.5/360.0*2*m.pi))")
CY23_1=$(python -c "import math as m; print($CR23*m.sin(22.5/360.0*2*m.pi))")
CY23_2=$(python -c "import math as m; print($CR23*m.sin(67.5/360.0*2*m.pi))")

DX26=$(python -c "print($CR02*0.65+$CR12*0.35)")
DZ26=$(python -c "print($CZ02*0.5+$CZ12*0.5)")
DY2327=$(python -c "print($CR02*0.65+$CR12*0.35)")
DZ2327=$(python -c "print($CZ02*0.5+$CZ12*0.5)")
DX1316=$(python -c "print(($CR02*0.65+$CR12*0.35)/$SQRT2)")
DY1316=$(python -c "print(($CR02*0.6+$CR12*0.4)/$SQRT2)")
DZ1316=$(python -c "print($CZ02*0.5+$CZ12*0.5)")

##

COSPR0=$(python -c "import math as m; print(m.cos($ALPHA0/360.0*2*m.pi)*$PR0)")
SINPR0=$(python -c "import math as m; print(m.sin($ALPHA0/360.0*2*m.pi)*$PR0)")
COSPR1=$(python -c "import math as m; print(m.cos($ALPHA0/360.0*2*m.pi)*$PR1)")
SINPR1=$(python -c "import math as m; print(m.sin($ALPHA0/360.0*2*m.pi)*$PR1)")

##

m4 \
    -DVARSQRT2=$SQRT2 \
    -DVARCR00=$CR00 \
    -DVARCR01=$CR01 \
    -DVARCR02=$CR02 \
    -DVARCR03=$CR03 \
    -DVARCR10=$CR10 \
    -DVARCR11=$CR11 \
    -DVARCR12=$CR12 \
    -DVARCR13=$CR13 \
    -DVARCR20=$CR20 \
    -DVARCR21=$CR21 \
    -DVARCR22=$CR22 \
    -DVARCR23=$CR23 \
    -DVARALPHAROOF=$ALPHAROOF \
    -DVARCZ00=$CZ00 \
    -DVARCZ10=$CZ10 \
    -DVARCZ20=$CZ20 \
    -DVARCZ01=$CZ01 \
    -DVARCZ11=$CZ11 \
    -DVARCZ21=$CZ21 \
    -DVARCZ02=$CZ02 \
    -DVARCZ12=$CZ12 \
    -DVARCZ22=$CZ22 \
    -DVARCZ03=$CZ03 \
    -DVARCZ13=$CZ13 \
    -DVARCZ23=$CZ23 \
    -DVARCBZ10=$CBZ10 \
    -DVARCBZ9=$CBZ9 \
    -DVARCBZ8=$CBZ8 \
    -DVARCBZ7=$CBZ7 \
    -DVARCBZ6=$CBZ6 \
    -DVARCBZ5=$CBZ5 \
    -DVARCBZ4=$CBZ4 \
    -DVARCBZ3=$CBZ3 \
    -DVARCBZ2=$CBZ2 \
    -DVARCBZ1=$CBZ1 \
    -DVARCBZ0=$CBZ0 \
    -DVARCBR10=$CBR10 \
    -DVARCBR9=$CBR9 \
    -DVARCBR8=$CBR8 \
    -DVARCBR7=$CBR7 \
    -DVARCBR6=$CBR6 \
    -DVARCBR5=$CBR5 \
    -DVARCBR4=$CBR4 \
    -DVARCBR3=$CBR3 \
    -DVARCBR2=$CBR2 \
    -DVARCBR1=$CBR1 \
    -DVARCBR0=$CBR0 \
    -DVARCNR0=$CNR0 \
    -DVARCNR1=$CNR1 \
    -DVARCNR2=$CNR2 \
    -DVARCNZ0=$CNZ0 \
    -DVARCNZ1=$CNZ1 \
    -DVARALPHA0=$ALPHA0 \
    -DVARALPHA1=$ALPHA1 \
    -DVARPXX0=$PXX0 \
    -DVARPXX1=$PXX1 \
    -DVARPYY0=$PYY0 \
    -DVARPYY1=$PYY1 \
    -DVARPX2=$PX2 \
    -DVARPX3=$PX3 \
    -DVARPX4=$PX4 \
    -DVARPR0=$PR0 \
    -DVARPR1=$PR1 \
    -DVARPZ0=$PZ0 \
    -DVARPZ1=$PZ1 \
    -DVARPZ2=$PZ2 \
    -DVARPZ3=$PZ3 \
    -DVARPZ4=$PZ4 \
    -DVARPZ5=$PZ5 \
    -DVARPZ6=$PZ6 \
    -DVARPY1=$PY1 \
    -DVARPY2=$PY2 \
    -DVARPY3=$PY3 \
    -DVARPY4=$PY4 \
    -DVARPY5=$PY5 \
    -DVARPPR0=$PPR0 \
    -DVARPPR1=$PPR1 \
    -DVARPPR2=$PPR2 \
    -DVARPPR3=$PPR3 \
    -DVARPPR4=$PPR4 \
    -DVARPPZ0=$PPZ0 \
    -DVARPPZ1=$PPZ1 \
    -DVARPPZ2=$PPZ2 \
    -DVARPPZ3=$PPZ3 \
    -DVARPPZ4=$PPZ4 \
    -DVARPPY0=$PPY0 \
    -DVARPPY1=$PPY1 \
    -DVARPPY2=$PPY2 \
    -DVARPPY3=$PPY3 \
    -DVARPPY4=$PPY4 \
    -DVARPAX0=$PAX0 \
    -DVARPAX1=$PAX1 \
    -DVARPAY0=$PAY0 \
    -DVARPAY1=$PAY1 \
    -DVARPAZ0=$PAZ0 \
    -DVARPAZ1=$PAZ1 \
    -DVARPNX0=$PNX0 \
    -DVARPNX1=$PNX1 \
    -DVARPNX2=$PNX2 \
    -DVARPNY0=$PNY0 \
    -DVARPNY1=$PNY1 \
    -DVARPNZ0=$PNZ0 \
    -DVARPNZ1=$PNZ1 \
    -DVARPNB=$PNB \
    -DVARF=$F \
    -DVARCR01M=$CR01M \
    -DVARCR02M=$CR02M \
    -DVARCR03M=$CR03M \
    -DVARCR11M=$CR11M \
    -DVARCR12M=$CR12M \
    -DVARCR13M=$CR13M \
    -DVARCR21M=$CR21M \
    -DVARCR22M=$CR22M \
    -DVARCR23M=$CR23M \
    -DVARCZ01M=$CZ01M \
    -DVARCZ02M=$CZ02M \
    -DVARCZ03M=$CZ03M \
    -DVARCZ11M=$CZ11M \
    -DVARCZ12M=$CZ12M \
    -DVARCZ13M=$CZ13M \
    -DVARCZ21M=$CZ21M \
    -DVARCZ22M=$CZ22M \
    -DVARCZ23M=$CZ23M \
    -DVARCBR0M=$CBR0M \
    -DVARCBR1M=$CBR1M \
    -DVARCBR2M=$CBR2M \
    -DVARCBR3M=$CBR3M \
    -DVARCBR4M=$CBR4M \
    -DVARCBR5M=$CBR5M \
    -DVARCBR6M=$CBR6M \
    -DVARCBR7M=$CBR7M \
    -DVARCBR8M=$CBR8M \
    -DVARCBR9M=$CBR9M \
    -DVARCBR10M=$CBR10M \
    -DVARCX02_1=$CX02_1 \
    -DVARCX02_2=$CX02_2 \
    -DVARCY02_1=$CY02_1 \
    -DVARCY02_2=$CY02_2 \
    -DVARCX12_1=$CX12_1 \
    -DVARCX12_2=$CX12_2 \
    -DVARCY12_1=$CY12_1 \
    -DVARCY12_2=$CY12_2 \
    -DVARCX22_1=$CX22_1 \
    -DVARCX22_2=$CX22_2 \
    -DVARCY22_1=$CY22_1 \
    -DVARCY22_2=$CY22_2 \
    -DVARCX03_1=$CX03_1 \
    -DVARCX03_2=$CX03_2 \
    -DVARCY03_1=$CY03_1 \
    -DVARCY03_2=$CY03_2 \
    -DVARCX13_1=$CX13_1 \
    -DVARCX13_2=$CX13_2 \
    -DVARCY13_1=$CY13_1 \
    -DVARCY13_2=$CY13_2 \
    -DVARCX23_1=$CX23_1 \
    -DVARCX23_2=$CX23_2 \
    -DVARCY23_1=$CY23_1 \
    -DVARCY23_2=$CY23_2 \
    -DVARDX26=$DX26 \
    -DVARDZ26=$DZ26 \
    -DVARDY2327=$DY2327 \
    -DVARDZ2327=$DZ2327 \
    -DVARDX1316=$DX1316 \
    -DVARDY1316=$DY1316 \
    -DVARDZ1316=$DZ1316 \
    -DVARCOSPR0=$COSPR0 \
    -DVARSINPR0=$SINPR0 \
    -DVARCOSPR1=$COSPR1 \
    -DVARSINPR1=$SINPR1 \
        $FILE
