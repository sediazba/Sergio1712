set terminal pdf
set output 'RK4_OA.pdf'

set style line 1 lt 1 lw 2 lc rgb 'blue' pt 7 ps 0.5
set style line 2 lt 1 lw 2 lc rgb 'red' pt 5 ps 0.5
set style line 3 lt 1 lw 2 lc rgb 'black' pt 2 ps 0.5


set title "Oscilador Armónico"
set xlabel "Tiempo"
set ylabel "X"


set key top right

plot "datos.txt" using 1:2 with linespoints linestyle 1 title "X"