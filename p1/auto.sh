#!/bin/bash

mkdir -p datos
mkdir -p ejecutables

./creacion_tiempos.sh burbuja.cpp datos ejecutables 2000 51000 2000
./creacion_tiempos.sh floyd.cpp datos ejecutables 50 1500 50
./creacion_tiempos.sh hanoi.cpp datos ejecutables 5 31 1
./creacion_tiempos.sh heapsort.cpp datos ejecutables 5000 150000 5000
./creacion_tiempos2.sh insercion.cpp datos ejecutables 2000 51000 2000
./creacion_tiempos.sh mergesort.cpp datos ejecutables 5000 150000 5000
./creacion_tiempos.sh quicksort.cpp datos ejecutables 5000 150000 5000
./creacion_tiempos2.sh seleccion.cpp datos ejecutables 2000 51000 2000
