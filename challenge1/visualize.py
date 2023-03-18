import matplotlib.pyplot as plt
import numpy as np

matrix = np.loadtxt("output.txt")
t = matrix[:,0]
y = matrix[:,1]

plt.figure(figsize=(15,12))
plt.plot(t, y, linestyle='--', marker='o')

t = np.linspace(0, 1, 100)
f_ex = lambda x: np.log(1-0.5*x**2)
y_ex = f_ex(t)
plt.plot(t, y_ex)
plt.savefig("output.png")