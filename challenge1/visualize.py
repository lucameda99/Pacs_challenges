import matplotlib.pyplot as plt
import numpy as np

matrix = np.loadtxt("output.txt")
t = matrix[:,0]
y = matrix[:,1]

plt.figure(figsize=(15,12))
plt.plot(t, y, linestyle='--', marker='o', label = 'CN')

t = np.linspace(0, 1, 100)
f_ex = lambda x: np.log(1-0.5*x**2)
y_ex = f_ex(t)
plt.plot(t, y_ex, label = 'exact')
plt.legend()
plt.title('Solution')
plt.savefig("output.png")

# create plot for convergence rate
matrix = np.loadtxt("convergence_rate.txt") # , delimiter=' ')
t = matrix[:,0]
y = matrix[:,1]

plt.figure(figsize=(15,12))
plt.semilogy(t, y, linestyle='--', marker='o', label = 'convergence')

h1 = t**(-1)
plt.semilogy(t, h1, label = 'h^-1')

h2 = t**(-2)
plt.semilogy(t, h2, label = 'h^-2')

plt.legend()
plt.title('Convergence Rate')
plt.savefig("convergence_rate.png")