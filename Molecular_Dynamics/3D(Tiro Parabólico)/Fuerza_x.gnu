set terminal pdf
set output 'Fuerza x.pdf'

set style line 1 lt 1 lw 2 lc rgb 'blue' pt 7 ps 0.5

set title "Molecular Dynamics"
set xlabel "Tiempo"
set ylabel "Fuerza x"

plot "datos3D.txt" using 1:5 with linespoints linestyle 1