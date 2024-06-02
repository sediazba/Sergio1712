import matplotlib.pyplot as plt
import numpy as np

h, o1, o2, o3, o4, o5, ro1, ro2, ro3, ro4, ro5 = np.genfromtxt('derivaties.txt', unpack=True)

plt.loglog(h, o1, '-o', label="o1")
plt.loglog(h, o2, '-s', label="o2")
plt.loglog(h, o3, '-*', label="o3")
plt.loglog(h, o4, '-^', label="o4")
plt.loglog(h, o5, '-D', label="o5")
plt.loglog(h, ro1, '-o', label="ro1")
plt.loglog(h, ro2, '-s', label="ro2")
plt.loglog(h, ro3, '-*', label="ro3")
plt.loglog(h, ro4, '-^', label="ro4")
plt.loglog(h, ro5, '-D', label="ro5")

plt.xlabel('Valor de h')
plt.ylabel('Error derivada')
plt.title('Error de la derivada en función de h')
plt.legend()
plt.savefig("Gráfica_derivación.pdf")
plt.show()
