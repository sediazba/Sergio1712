set terminal pdf
set output 'Euler_vs_RK4.pdf'

set style line 1 lt 1 lw 2 lc rgb 'blue' pt 5 ps 0.5
set style line 2 lt 1 lw 2 lc rgb 'red' pt 5 ps 0.5
set style line 3 lt 1 lw 2 lc rgb 'black' pt 5 ps 0.5


set title "EDO dydt= 5sint + t"
set xlabel "t"
set ylabel "y"
set xrange[5:10]



set key top left

plot "datos_euler.txt" using 1:2 with linespoints linestyle 1 title "EULER", "datos_rk4.txt" using 1:2 with linespoints linestyle 2 title "RK4", -5*cos(x) + 0.5*x*x + 6.5 with linespoints linestyle 3 title "ORIGINAL"