#!/bin/sh

filename=$(basename "$1")
extension="${filename##*.}"
filename="${filename%.*}"

gnuplot << EOF

#! /usr/bin/gnuplot

set terminal epslatex size 5,3 color colortext

set border linewidth 2 linecolor rgb '#4D4D4D'
set style line 1 linecolor rgb '#811a18' linetype 1 linewidth 5
set style line 2 linecolor rgb '#814918' linetype 1 linewidth 5
set style line 3 linecolor rgb '#136618' linetype 1 linewidth 5
set style line 4 linecolor rgb '#0F4B4E' linetype 1 linewidth 5
set style line 5 linecolor rgb '#681341' linetype 1 linewidth 5
set style line 6 linecolor rgb '#1F1B5A' linetype 1 linewidth 5


set format x '$\textcolor{text}{%g}$'
set format y '$\textcolor{text}{%g}$'
set xlabel "Número de vectores (k)" tc '#4D4D4D' offset 0,1.5
set ylabel "Tiempo de ejecución (s)" tc '#4D4D4D' offset 2,0
set logscale y

set xtics rotate by 45 right font ", 8"

set output "./graficos/compare.tex"
set title "Algoritmos mezcla de k vectores" tc '#4D4D4D'
set key outside

plot "./dat/mezcla-vectores-clasico.dat" with lines linestyle 1 title "Clásico", \
"./dat/mezcla-vectores-DyV.dat" with lines linestyle 2 title "DyV", \
"./dat/mezcla-vectores-DyV-STL.dat" with lines linestyle 3 title "DyV STL" \

EOF
