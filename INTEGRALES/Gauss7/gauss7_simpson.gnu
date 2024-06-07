set terminal pdf
set output 'Gauss7_simpson.pdf'

set style line 1 lt 1 lw 2 lc rgb 'blue' pt 7 ps 0.5
set style line 2 lt 1 lw 2 lc rgb 'red' pt 5 ps 0.5


set title "Gauss7 vs R. Simpson"
set xlabel "# Puntos"
set ylabel "Errores integrales"

set key top right

plot "datos.txt" using 1:2 with linespoints linestyle 1 title "Gauss 7", "datos.txt" using 1:3 with linespoints linestyle 2 title "Richardon Simpson"