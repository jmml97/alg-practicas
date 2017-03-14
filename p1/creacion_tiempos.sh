#!/bin/bash
# Uso ./creacion_tiempos.sh nombre_algoritmo ruta_carpeta_datos ruta_carpeta_ejecutables


# Creacion de los ejecutables
# -----------------------------------------------------------

NOMBRE=`echo "$1" | cut -d'.' -f1`
CPP=algoritmos_cpp/$1
C_EJECUTABLES=`echo ${3}/${NOMBRE}_ejecutables`

EJE_O0=`echo ${NOMBRE}-linux-O0`
EJE_O1=`echo ${NOMBRE}-linux-O1`
EJE_O2=`echo ${NOMBRE}-linux-O2`
EJE_O3=`echo ${NOMBRE}-linux-O3`

mkdir -p $C_EJECUTABLES
g++ -O0 $CPP -o $C_EJECUTABLES/$EJE_O0
g++ -O1 $CPP -o $C_EJECUTABLES/$EJE_O1
g++ -O2 $CPP -o $C_EJECUTABLES/$EJE_O2
g++ -O3 $CPP -o $C_EJECUTABLES/$EJE_O3

# -----------------------------------------------------------

# Salida de datos
# -----------------------------------------------------------

C_DATOS=`echo ${2}/${NOMBRE}_datos`

DAT_O0=$EJE_O0.dat
DAT_O1=$EJE_O1.dat
DAT_O2=$EJE_O2.dat
DAT_O3=$EJE_O3.dat

mkdir -p $C_DATOS
rm -f $C_DATOS/$DAT_O0
rm -f $C_DATOS/$DAT_O1
rm -f $C_DATOS/$DAT_O2
rm -f $C_DATOS/$DAT_O3

i=$4
TAM_MAX=$5

echo Tiempos $NOMBRE
echo ------------------------------------------------------

while [ $i -lt $TAM_MAX ];
do
  echo Valor: $i
  $C_EJECUTABLES/$EJE_O0 $i >> $C_DATOS/$DAT_O0
  $C_EJECUTABLES/$EJE_O1 $i >> $C_DATOS/$DAT_O1
  $C_EJECUTABLES/$EJE_O2 $i >> $C_DATOS/$DAT_O2
  $C_EJECUTABLES/$EJE_O3 $i >> $C_DATOS/$DAT_O3
  ((i += $6))
done

echo ""

# -----------------------------------------------------------
