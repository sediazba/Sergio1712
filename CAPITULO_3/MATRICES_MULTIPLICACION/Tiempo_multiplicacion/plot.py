import matplotlib.pyplot as plt
import numpy as np

S, T = np.genfromtxt('datos.txt', unpack=True) Primer valor X segundo Y

plt.loglog(S, T, marker='o', linestyle='-', markersize = 5)         loglog es la escala, o plot en normal

plt.xlabel("Matrix Size")          Titulo de X
plt.ylabel("Mult Time")            Otra manera de poner escala: plt.xscale('log') plt.yscale('log')

# Agregar título del gráfico
plt.title("Tamaño contra Tiempo de Multiplicacion")

plt.savefig("Tamaño contra Tiempo de Multiplicacion.pdf")


