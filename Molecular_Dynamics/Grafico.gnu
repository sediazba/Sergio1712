set terminal pdf
set output 'Molecular_Dynamics.pdf'

set style line 1 lt 1 lw 2 lc rgb 'blue' pt 7 ps 0.5
set style line 2 lt 1 lw 2 lc rgb 'red' pt 7 ps 0.5
set style line 3 lt 1 lw 2 lc rgb 'black' pt 7 ps 0.5


set title "Molecular Dynamics"
set xlabel "Tiempo"
set ylabel "Rz, Vz, Fz"

set key bottom right

plot "datos.txt" using 1:3 with linespoints linestyle 1 title "Rz", "datos.txt" using 1:4 with linespoints linestyle 2 title "Vz", "datos.txt" using 1:5 with linespoints linestyle 3 title "Fz"