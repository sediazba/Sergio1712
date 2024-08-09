set terminal pdf
set output 'Euler_vs_RK4.pdf'

set style line 1 lt 1 lw 2 lc rgb 'blue' pt 5 ps 0.5
set style line 2 lt 1 lw 2 lc rgb 'red' pt 5 ps 0.5


set title "EDO"
set xlabel "t"
set ylabel "y"
set yrange [0:10]



set key top left

plot "datoseuler.txt" using 1:2 with linespoints linestyle 1 title "EULER", "datosrk4.txt" using 1:2 with linespoints linestyle 2 title "RK4"