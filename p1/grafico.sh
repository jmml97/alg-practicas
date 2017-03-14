#!/bin/sh

filename=$(basename "$1")
extension="${filename##*.}"
filename="${filename%.*}"

gnuplot << EOF

#! /usr/bin/gnuplot

set terminal epslatex size 4,3 color colortext
set output "./graficos/$filename.tex"

set border linewidth 2 linecolor rgb '#4D4D4D'
set style line 1 linecolor rgb '#811a18' linetype 1 linewidth 5
set format x '$\textcolor{text}{%g}$'
set format y '$\textcolor{text}{%g}$'
set xlabel "Tamaño del vector (elementos)" tc '#4D4D4D' offset 0,1.5
set ylabel "Tiempo de ejecución (s)" tc '#4D4D4D' offset 2,0

set xtics rotate by 45 right font ", 8"

set style line 2 linecolor rgb '#dd181f' linetype 1 linewidth 5
#set tics scale 1.25

set title "$filename" tc '#4D4D4D'
#set key left box
#set samples 50
set style data points

plot "$1" with lines linestyle 1 title ""


EOF
