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
g(x) = x*b0*x**b1+x*b2
h(x) = c0*x*x*x+c1*x*x+c2*x+c3
i(x) = d0*2**(x*d1)+d2

# Algoritmos de ordenación n^2

fit f(x) "./datos/burbuja_datos/burbuja-linux-O0.dat" via a0,a1,a2

set output "./graficos/ajuste-burbuja.tex"
set title "Ajuste burbuja" tc '#4D4D4D'

plot f(x) with lines linestyle 3 title "Burbuja ajustada", "./datos/burbuja_datos/burbuja-linux-O0.dat" with points linestyle 1 pt 7 title "Burbuja"

fit f(x) "./datos/insercion_datos/insercion-linux-O0.dat" via a0,a1,a2

set output "./graficos/ajuste-insercion.tex"
set title "Ajuste inserción" tc '#4D4D4D'

plot f(x) with lines linestyle 3 title "Inserción ajustado", "./datos/insercion_datos/insercion-linux-O0.dat" with points linestyle 1 pt 7 title "Inserción"

fit f(x) "./datos/seleccion_datos/seleccion-linux-O0.dat" via a0,a1,a2

set output "./graficos/ajuste-seleccion.tex"
set title "Ajuste selección" tc '#4D4D4D'

plot f(x) with lines linestyle 3 title "Selección ajustado", "./datos/seleccion_datos/seleccion-linux-O0.dat" with points linestyle 1 pt 7 title "Selección"

# Algoritmos de ordenación nlogn

fit g(x) "./datos/mergesort_datos/mergesort-linux-O0.dat" via b0,b1,b2

set output "./graficos/ajuste-mergesort.tex"
set title "Ajuste mergesort" tc '#4D4D4D'
set logscale y

plot g(x) with lines linestyle 3 title "Mergesort ajustado", "./datos/mergesort_datos/mergesort-linux-O0.dat" with points linestyle 1 pt 7 title "Mergesort"

fit g(x) "./datos/heapsort_datos/heapsort-linux-O0.dat" via b0,b1,b2

set output "./graficos/ajuste-heapsort.tex"
set title "Ajuste heapsort" tc '#4D4D4D'

plot g(x) with lines linestyle 3 title "Heapsort ajustado", "./datos/heapsort_datos/heapsort-linux-O0.dat" with points linestyle 1 pt 7 title "Heapsort"

fit g(x) "./datos/quicksort_datos/quicksort-linux-O0.dat" via b0,b1,b2

set output "./graficos/ajuste-quicksort.tex"
set title "Ajuste quicksort" tc '#4D4D4D'

plot g(x) with lines linestyle 3 title "Quicksort ajustado", "./datos/quicksort_datos/quicksort-linux-O0.dat" with points linestyle 1 pt 7 title "Quicksort"

fit h(x) "./datos/floyd_datos/floyd-linux-O0.dat" via c0,c1,c2,c3

set output "./graficos/ajuste-floyd.tex"
set title "Ajuste floyd" tc '#4D4D4D'
unset logscale y

plot h(x) with lines linestyle 3 title "Floyd ajustado", "./datos/floyd_datos/floyd-linux-O0.dat" with points linestyle 1 pt 7 title "Floyd"

fit i(x) "./datos/hanoi_datos/hanoi-linux-O0.dat" via d0, d1,d2

set output "./graficos/ajuste-hanoi.tex"
set title "Ajuste hanoi" tc '#4D4D4D'

plot i(x) with lines linestyle 3 title "Hanoi ajustado", "./datos/hanoi_datos/hanoi-linux-O0.dat" with points linestyle 1 pt 7 title "Hanoi"

EOF
