import matplotlib.pyplot as plt
import numpy as np

h, V = np.genfromtxt('datos.txt', unpack=True) 

plt.plot(h, V, 'o', label = "Datos")

m = 4.088227358517516e-15
b = -1.731235803981356e+00   

regression_line = m * h + b

plt.plot(h, regression_line, '-', label = "Regresion lineal")

plt.xlabel("Frecuencia de luz incidente")
plt.ylabel("Voltaje")

# Agregar título del gráfico
plt.title("Regresión efecto fotoeléctrico")

plt.legend(["Datos", "\nRegresion lineal \n\nDatos programa: \nh = 6.550062348296306e-33  \nphi = 1.731235803981356e+00"])
 
plt.savefig("Regresion_efecto_fotoelectrico.pdf")

# Mostrar la gráfica
plt.show()

