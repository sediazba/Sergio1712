set terminal pdf
set parametric
set output 'Circle.pdf'

set style line 1 lt 1 lw 2 lc rgb 'blue' pt 7 ps 0.5

set xlabel "x"
set ylabel "z"

set trange [0:2*pi]
set xrange [-2:3]
set yrange [-2:3]
r = 1
plot 1 + r*cos(t), 1 + r*sin(t) title 'Círculo centrado en (1,1)', "datos.txt" using 3:5 with linespoints linestyle 1 title "Z vs X"