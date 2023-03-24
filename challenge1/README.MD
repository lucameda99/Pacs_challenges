# Project developed by Emanuele Tamburini and Luca Meda #

For this challenge we have developed a Class `ODESolver` to solve the proposed ODE, having as member the parameters indicated (T, N, f), vectors to store the result solution at each timestep and a parameter theta to implement the more general theta method (which has as default value 0.5 equivalent to solving the ODE with the proposed Crank Nicolson method).

In the main file we added a function test convergence to check the order of convergence of our method comparing the L2 norm of the computed solution against the reference solution.

In the folder we added a shell script named `autorun.sh` containing simple commands to make, run the executable (by default it runs the muparser version, see below) and calling a python script that produces the plot of the solution alongside with a plot comparing the order of converge of the method with the reference order 1 and order 2 convergence.

The Makefile produces two executables, `main` and `main_getplot_muparser`, where the former is related to the standard version of our implementation, the latter to the version that exploits muparser reading parameters from the text file `data.txt`


