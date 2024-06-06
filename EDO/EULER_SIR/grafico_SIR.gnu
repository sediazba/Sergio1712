set terminal pdf
set output 'SIR.pdf'

set style line 1 lt 1 lw 2 lc rgb 'blue' pt 7 ps 0.5
set style line 2 lt 1 lw 2 lc rgb 'red' pt 5 ps 0.5
set style line 3 lt 1 lw 2 lc rgb 'black' pt 2 ps 0.5


set title "SIR MODEL"
set xlabel "Tiempo"
set ylabel "Cantidad"


set key top right

plot "datos.txt" using 1:2 with linespoints linestyle 1 title "Susceptibles", "datos.txt" using 1:3 with linespoints linestyle 2 title "Infectados", "datos.txt" using 1:4 with linespoints linestyle 3 title "Recuperados"
