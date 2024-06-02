import matplotlib.pyplot as plt
import numpy as np

npoints, y_simp, y_trap, y_richsimp, y_richtrap = np.genfromtxt("integracion.txt", unpack=True)

plt.loglog(npoints, y_simp, label="Error Simpson", marker='o')
plt.loglog(npoints, y_trap, label="Error Trapezoid", marker='s')
plt.loglog(npoints, y_richsimp, label="Error Richardson + Simpson", marker='o')
plt.loglog(npoints, y_richtrap, label="Error Richardson + Trapezoid", marker='s')
plt.xlabel('Cantidad de Puntos')
plt.ylabel('Error Relativo')
plt.legend()
plt.savefig("integracion.pdf")
plt.show()