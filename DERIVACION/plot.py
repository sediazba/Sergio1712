import matplotlib.pyplot as plt
import numpy as np

x, y_forward, y_central = np.genfromtxt("derivacion.txt", unpack=True)

plt.loglog(x, y_forward, label="Error Derivada Froward", marker='o')
plt.loglog(x, y_central, label="Error Derivada Central", marker='s')
plt.xlabel('Valor de h')
plt.ylabel('Error Relativo')
plt.legend()
plt.savefig("derivacion.pdf")
plt.show()