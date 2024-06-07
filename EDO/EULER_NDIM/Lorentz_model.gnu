set terminal pdf
set output 'eulerNDIM_xyz.pdf'

set title "Lorentz Model XYZ"
set xlabel "X"
set ylabel "Y"
set zlabel "Z"

set key top right

# Habilitar la paleta de colores
set palette rgb 28,13,10

# Configurar el rango de la paleta de colores (ajusta según tus datos)
set cbrange [0:100]

# Configurar la barra de color (colorbox)
set colorbox
set colorbox vertical user origin .9, .2 size .01, .6

# Gráfico 3D con escala de colores basada en la columna 5
splot "datos.txt" using 2:3:4:5 with lines palette title "Lorentz model"
