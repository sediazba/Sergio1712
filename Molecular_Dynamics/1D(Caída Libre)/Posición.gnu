set terminal pdf
set output 'Posición.pdf'

set style line 1 lt 1 lw 2 lc rgb 'blue' pt 7 ps 0.5

set title "Molecular Dynamics"
set xlabel "Tiempo"
set ylabel "Posición"

plot "datos.txt" using 1:3 with linespoints linestyle 1