set terminal pdf
set output 'Fuerza z.pdf'

set style line 1 lt 1 lw 2 lc rgb 'blue' pt 7 ps 0.5

set title "Molecular Dynamics"
set xlabel "Tiempo"
set ylabel "Fuerza z"

plot "datos3D.txt" using 1:11 with linespoints linestyle 1