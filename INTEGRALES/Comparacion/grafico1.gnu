set terminal pdf
set output 'integrales.pdf'

set logscale y
set logscale x

set style line 1 lt 1 lw 2 lc rgb 'blue' pt 7 ps 0.5
set style line 2 lt 1 lw 2 lc rgb 'red' pt 5 ps 0.5
set style line 3 lt 1 lw 2 lc rgb 'black' pt 2 ps 0.5
set style line 4 lt 1 lw 2 lc rgb 'orange' pt 3 ps 0.5


set title "Error Integral Función Error"
set xlabel "# Puntos"
set ylabel "Errores integrales"

set format y "10^{%L}"
set format x "10^{%L}"

set key top right

plot "datos.txt" using 1:2 with linespoints linestyle 1 title "Trapezoid", "datos.txt" using 1:3 with linespoints linestyle 2 title "Simpson", "datos.txt" using 1:4 with linespoints linestyle 3 title "RICH Trapezoid", "datos.txt" using 1:5 with linespoints linestyle 4 title "RICH Simpson"
