#!/bin/sh

filename=$(basename "$1")
extension="${filename##*.}"
filename="${filename%.*}"

gnuplot << EOF

#! /usr/bin/gnuplot

set encoding utf8

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

f(x) = a0*5*x*x + a1*x + a2
g(x) = b0*10*x*log(x) + b1

# Clásico

fit f(x) "./dat/mezcla-vectores-clasico.dat" via a0,a1,a2
print a0, a1, a2

set output "./graficos/ajuste-clasico.tex"
#set title "".sprintf("%.2f\$\frac{n}{2}x^2\$+%.2f\$x\$+%.2f", a0, a1, a2) tc '#4D4D4D'
set title "Ajuste algoritmo clásico" tc '#4D4D4D'

plot f(x) with lines linestyle 3 title sprintf("%2.2e\$x^2\$+%2.2e\$x\$+%2.2e", a0, a1, a2), "./dat/mezcla-vectores-clasico.dat" with points linestyle 1 pt 7 title "Clásico"

# DyV

fit g(x) "./dat/mezcla-vectores-DyV.dat" via b0
print b0, b1

set output "./graficos/ajuste-DyV.tex"
#set title "".sprintf("\$ %2.2e \\\cdot k\\\log k + %2.2e k + %2.2e\$", b0, b1, b2) tc '#4D4D4D'
set title "Ajuste algoritmo divide y vencerás" tc '#4D4D4D'

plot f(x) with lines linestyle 3 title sprintf("%2.2e\$x^2\$+%2.2e\$x\$+%2.2e", b0, b1, b2), "./dat/mezcla-vectores-DyV.dat" with points linestyle 1 pt 7 title "Divide y vencerás"

# DyV STL

fit g(x) "./dat/mezcla-vectores-DyV-STL.dat" via b0,b1
print b0, b1

set output "./graficos/ajuste-DyV-STL.tex"
#set title "".sprintf("\$ %2.2e \\\cdot k\\\log k + %2.2e k + %2.2e\$", b0, b1, b2) tc '#4D4D4D'
set title "Ajuste algoritmo divide y vencerás STL" tc '#4D4D4D'

plot f(x) with lines linestyle 3 title sprintf("%2.2e\$x^2\$+%2.2e\$x\$+%2.2e", b0, b1, b2), "./dat/mezcla-vectores-DyV-STL.dat" with points linestyle 1 pt 7 title "Divide y vencerás STL"


EOF
