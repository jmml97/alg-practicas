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

f(x) = a0*x*x+a1*x+a2
g(x) = x*b0*x**b1
h(x) = c0*x*x*x+c1*x*x+c2*x+c3
i(x) = 2**x+d0

# Algoritmos de ordenación n^2

fit f(x) "./datos/burbuja_datos/burbuja-linux-O0.dat" via a0,a1,a2

set output "./graficos/ajuste-burbuja.tex"
set title "Algoritmos de ordenación \$O(n^2)$" tc '#4D4D4D'

plot f(x) with lines linestyle 3 title "Burbuja ajustada", "./datos/burbuja_datos/burbuja-linux-O0.dat" with points linestyle 1 pt 7 title "Burbuja"



EOF
