#!/bin/sh

filename=$(basename "$1")
extension="${filename##*.}"
filename="${filename%.*}"

gnuplot << EOF

#! /usr/bin/gnuplot

set terminal epslatex size 4,3 color colortext

set border linewidth 2 linecolor rgb '#4D4D4D'
set style line 1 linecolor rgb '#811a18' linetype 1 linewidth 5
set style line 2 linecolor rgb '#814918' linetype 1 linewidth 5
set style line 3 linecolor rgb '#136618' linetype 1 linewidth 5
set style line 4 linecolor rgb '#0F4B4E' linetype 1 linewidth 5
set style line 5 linecolor rgb '#681341' linetype 1 linewidth 5
set style line 6 linecolor rgb '#1F1B5A' linetype 1 linewidth 5


set format x '$\textcolor{text}{%g}$'
set format y '$\textcolor{text}{%g}$'
set xlabel "Tamaño del vector (elementos)" tc '#4D4D4D' offset 0,1.5
set ylabel "Tiempo de ejecución (s)" tc '#4D4D4D' offset 2,0

set xtics rotate by 45 right font ", 8"

# Algoritmos de ordenación n^2

set output "./graficos/ncuadrado.tex"
set title "Algoritmos de ordenación \$O(n^2)$" tc '#4D4D4D'

plot "./datos/burbuja_datos/burbuja-linux-O0.dat" with lines linestyle 1 title "Burbuja", \
"./datos/insercion_datos/insercion-linux-O0.dat" with lines linestyle 2 title "Inserción", \
"./datos/seleccion_datos/seleccion-linux-O0.dat" with lines linestyle 3 title "Selección" \

set terminal epslatex size 6,4.5 color colortext

# Algoritmos de ordenación nlogn

set output "./graficos/nlogn.tex"
set title "Algoritmos de ordenación \$O(nlogn)$" tc '#4D4D4D'
#set logscale y
set key outside

plot "./datos/mergesort_datos/mergesort-linux-O0.dat" with lines linestyle 1 title "Mergesort", \
"./datos/heapsort_datos/heapsort-linux-O0.dat" with lines linestyle 2 title "Heapsort", \
"./datos/quicksort_datos/quicksort-linux-O0.dat" with lines linestyle 3 title "Quicksort" \

# Todos los algoritmos de ordenación

set output "./graficos/ordenacion.tex"
set title "Algoritmos de ordenación" tc '#4D4D4D'
set logscale y

plot "./datos/mergesort_datos/mergesort-linux-O0.dat" with lines linestyle 1 title "Mergesort", \
"./datos/heapsort_datos/heapsort-linux-O0.dat" with lines linestyle 2 title "Heapsort", \
"./datos/quicksort_datos/quicksort-linux-O0.dat" with lines linestyle 3 title "Quicksort", \
"./datos/burbuja_datos/burbuja-linux-O0-extended.dat" with lines linestyle 4 title "Burbuja", \
"./datos/insercion_datos/insercion-linux-O0-extended.dat" with lines linestyle 5 title "Inserción", \
"./datos/seleccion_datos/seleccion-linux-O0-extended.dat" with lines linestyle 6 title "Selección"


EOF
