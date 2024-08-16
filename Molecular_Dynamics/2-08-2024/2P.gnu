set terminal pdf
set output '2P.pdf'

set style line 1 lt 1 lw 2 pt 7 ps 0.5
set style line 2 lt 1 lw 2 pt 7 ps 0.5

set xlabel "x"
set ylabel "z"

# Configuración de la paleta de colores de amarillo a rojo
set palette defined (0 "yellow", 1 "red")

plot "datos2p.txt" using 4:6:1 with linespoints linecolor palette title "1", "datos2p.txt" using 15:17:1 with linespoints linecolor palette title "2"
