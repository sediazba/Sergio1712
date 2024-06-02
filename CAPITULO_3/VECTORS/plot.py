import matplotlib.pyplot as plt
import numpy as np

x, y = np.genfromtxt('histo.txt', unpack=True) 

plt.plot(x, y, marker='o', linestyle='', markersize=5)

plt.savefig('plot.pdf')

plt.show()
