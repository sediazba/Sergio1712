import matplotlib.pyplot as plt
import numpy as np

h, V = np.genfromtxt('datos.txt', unpack=True) 

plt.plot(h, V, 'o', label="Datos")

m = 4.088227358517516e-15
b = -1.731235803981356e+00   

regression_line = m * h + b

plt.plot(h, regression_line, '-', label="Regresion lineal")

plt.xlabel("Frecuencia de luz incidente")
plt.ylabel("Voltaje")

# Agregar título del gráfico
plt.title("Regresión efecto fotoeléctrico")

# Agregar la leyenda
plt.legend()

# Coordenadas para la esquina inferior derecha
x_coord = 0.95
y_coord = 0.05

# Agregar texto personalizado para los valores de h y phi en la esquina inferior derecha
plt.text(x_coord, y_coord, "h = 6.550062348296306e-33\nphi = 1.731235803981356e+00",
         horizontalalignment='right', verticalalignment='bottom', transform=plt.gca().transAxes,
         bbox=dict(facecolor='none', edgecolor='black', boxstyle='round,pad=0.5'))

# Guardar el gráfico
plt.savefig("Regresion_efecto_fotoelectrico.pdf")

# Mostrar la gráfica
plt.show()


