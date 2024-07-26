set terminal pdf
set output 'Velocidad.pdf'

set style line 1 lt 1 lw 2 lc rgb 'red' pt 7 ps 0.5

set title "Molecular Dynamics"
set xlabel "Tiempo"
set ylabel "Velocidad"

plot "datos.txt" using 1:4 with linespoints linestyle 1