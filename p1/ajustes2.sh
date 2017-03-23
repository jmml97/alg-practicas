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

f(x) = a0*x*x+a1*x+a2
g(x) = b0*x*log(x) + b1*x + b2
h(x) = c0*x*x*x+c1*x*x+c2*x+c3
i(x) = d0*2**(x*d1)+d2

# Algoritmos de ordenación nlogn

fit g(x) "./datos/mergesort_datos/mergesort-linux-O0.dat" via b0,b1,b2

set output "./graficos/ajuste-mergesort.tex"
set title "Ajuste Mergesort" tc '#4D4D4D'


plot g(x) with lines linestyle 3 title sprintf("\$ %2.2e \\\cdot x\\\log x + %2.2e x + %2.2e\$", b0, b1, b2), "./datos/mergesort_datos/mergesort-linux-O0.dat" with points linestyle 1 pt 7 title "Mergesort"

fit g(x) "./datos/heapsort_datos/heapsort-linux-O0.dat" via b0,b1,b2

set output "./graficos/ajuste-heapsort.tex"
set title "Ajuste Heapsort" tc '#4D4D4D'

plot g(x) with lines linestyle 3 title sprintf("\$ %2.2e \\\cdot x\\\log x + %2.2e x + %2.2e\$", b0, b1, b2), "./datos/heapsort_datos/heapsort-linux-O0.dat" with points linestyle 1 pt 7 title "Heapsort"

fit g(x) "./datos/quicksort_datos/quicksort-linux-O0.dat" via b0,b1,b2

set output "./graficos/ajuste-quicksort.tex"
set title "Ajuste Quicksort" tc '#4D4D4D'

plot g(x) with lines linestyle 3 title sprintf("\$ %2.2e \\\cdot x\\\log x + %2.2e x + %2.2e\$", b0, b1, b2), "./datos/quicksort_datos/quicksort-linux-O0.dat" with points linestyle 1 pt 7 title "Quicksort"

EOF
