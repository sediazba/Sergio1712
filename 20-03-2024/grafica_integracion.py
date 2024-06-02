import matplotlib.pyplot as plt
import numpy as np

N, Simp, Trap, Rtrap, Rsimp = np.genfromtxt('integrales.txt', unpack=True)

plt.loglog(N, Simp, '-o', label="Simp")
plt.loglog(N, Trap, '-s', label="Trap")
plt.loglog(N, Rtrap, '-*', label="Rtrap")
plt.loglog(N, Rsimp, '-^', label="Rsimp")


plt.xlabel('Valor de h')
plt.ylabel('Error integral')
plt.title('Error de la integral en función de la Cantidad de subintervalos')
plt.legend()
plt.savefig("Gráfica_integración.pdf")
plt.show()
