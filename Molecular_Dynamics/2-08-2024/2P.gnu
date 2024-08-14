set terminal pdf
set output '2P.pdf'

set style line 1 lt 1 lw 2 lc rgb 'blue' pt 7 ps 0.5
set style line 2 lt 1 lw 2 lc rgb 'red' pt 7 ps 0.5 

set xlabel "x"
set ylabel "z"

plot "datos2.txt" using 4:6 with linespoints linestyle 1 title "1", "datos2.txt" using 15:17 with linespoints linestyle 2 title "2"