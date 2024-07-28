set terminal pdf
set output 'Velocidad x.pdf'

set style line 1 lt 1 lw 2 lc rgb 'blue' pt 7 ps 0.5

set title "Molecular Dynamics"
set xlabel "Tiempo"
set ylabel "Velocidad x"

plot "datos3D.txt" using 1:4 with linespoints linestyle 1