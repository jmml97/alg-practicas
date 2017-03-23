#!/bin/sh

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

# Burbuja mac-linux

set output "./graficos/burbuja-maclinux.tex"
set title "Comparación burbuja en macOS y Linux" tc '#4D4D4D'

plot "./datos/burbuja_datos/burbuja-linux-O0.dat" with lines linestyle 1 title "Linux", \
"./datos/burbuja_datos/burbuja-mac-O0.dat" with lines linestyle 2 title "Mac" \

# Inserción mac-linux

set output "./graficos/insercion-maclinux.tex"
set title "Comparación inserción en macOS y Linux" tc '#4D4D4D'

plot "./datos/insercion_datos/insercion-linux-O0.dat" with lines linestyle 1 title "Linux", \
"./datos/insercion_datos/insercion-mac-O0.dat" with lines linestyle 2 title "Mac" \

# Selección mac-linux

set output "./graficos/seleccion-maclinux.tex"
set title "Comparación selección en macOS y Linux" tc '#4D4D4D'

plot "./datos/seleccion_datos/seleccion-linux-O0.dat" with lines linestyle 1 title "Linux", \
"./datos/seleccion_datos/seleccion-mac-O0.dat" with lines linestyle 2 title "Mac" \

# Mergesort mac-linux

set output "./graficos/mergesort-maclinux.tex"
set title "Comparación mergesort en macOS y Linux" tc '#4D4D4D'

plot "./datos/mergesort_datos/mergesort-linux-O0.dat" with lines linestyle 1 title "Linux", \
"./datos/mergesort_datos/mergesort-mac-O0.dat" with lines linestyle 2 title "Mac" \

# Heapsort mac-linux

set output "./graficos/heapsort-maclinux.tex"
set title "Comparación heapsort en macOS y Linux" tc '#4D4D4D'

plot "./datos/heapsort_datos/heapsort-linux-O0.dat" with lines linestyle 1 title "Linux", \
"./datos/heapsort_datos/heapsort-mac-O0.dat" with lines linestyle 2 title "Mac" \

# Quicksort mac-linux

set output "./graficos/quicksort-maclinux.tex"
set title "Comparación quicksort en macOS y Linux" tc '#4D4D4D'

plot "./datos/quicksort_datos/quicksort-linux-O0.dat" with lines linestyle 1 title "Linux", \
"./datos/quicksort_datos/quicksort-mac-O0.dat" with lines linestyle 2 title "Mac" \

# Floyd mac-linux

set output "./graficos/floyd-maclinux.tex"
set title "Comparación floyd en macOS y Linux" tc '#4D4D4D'

plot "./datos/floyd_datos/floyd-linux-O0.dat" with lines linestyle 1 title "Linux", \
"./datos/floyd_datos/floyd-mac-O0.dat" with lines linestyle 2 title "Mac" \

# Hanoi mac-linux

set output "./graficos/hanoi-maclinux.tex"
set title "Comparación hanoi en macOS y Linux" tc '#4D4D4D'

plot "./datos/hanoi_datos/hanoi-linux-O0.dat" with lines linestyle 1 title "Linux", \
"./datos/hanoi_datos/hanoi-mac-O0.dat" with lines linestyle 2 title "Mac" \


# Inserción linux optimización

set output "./graficos/insercion-linux-opt.tex"
set title "Comparación inserción en Linux con distinta optimización" tc '#4D4D4D'

plot "./datos/insercion_datos/insercion-linux-O0.dat" with lines linestyle 1 title "O0", \
"./datos/insercion_datos/insercion-linux-O1.dat" with lines linestyle 2 title "O1", \
"./datos/insercion_datos/insercion-linux-O2.dat" with lines linestyle 3 title "O2", \
"./datos/insercion_datos/insercion-linux-O3.dat" with lines linestyle 4 title "O3" \

# Quicksort linux optimización

set output "./graficos/quicksort-linux-opt.tex"
set title "Comparación quicksort en Linux con distinta optimización" tc '#4D4D4D'

plot "./datos/quicksort_datos/quicksort-linux-O0.dat" with lines linestyle 1 title "O0", \
"./datos/quicksort_datos/quicksort-linux-O1.dat" with lines linestyle 2 title "O1", \
"./datos/quicksort_datos/quicksort-linux-O2.dat" with lines linestyle 3 title "O2", \
"./datos/quicksort_datos/quicksort-linux-O3.dat" with lines linestyle 4 title "O3" \

# Floyd linux optimización

set output "./graficos/floyd-linux-opt.tex"
set title "Comparación floyd en Linux con distinta optimización" tc '#4D4D4D'

plot "./datos/floyd_datos/floyd-linux-O0.dat" with lines linestyle 1 title "O0", \
"./datos/floyd_datos/floyd-linux-O1.dat" with lines linestyle 2 title "O1", \
"./datos/floyd_datos/floyd-linux-O2.dat" with lines linestyle 3 title "O2", \
"./datos/floyd_datos/floyd-linux-O3.dat" with lines linestyle 4 title "O3" \

# Hanoi linux optimización

set output "./graficos/hanoi-linux-opt.tex"
set title "Comparación floyd en Linux con distinta optimización" tc '#4D4D4D'

plot "./datos/hanoi_datos/hanoi-linux-O0.dat" with lines linestyle 1 title "O0", \
"./datos/hanoi_datos/hanoi-linux-O1.dat" with lines linestyle 2 title "O1", \
"./datos/hanoi_datos/hanoi-linux-O2.dat" with lines linestyle 3 title "O2", \
"./datos/hanoi_datos/hanoi-linux-O3.dat" with lines linestyle 4 title "O3" \

EOF
