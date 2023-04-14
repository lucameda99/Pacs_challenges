#Assignment 2#

We implemented a set of classes that derive from an abstract SolverBase class, with the pure virtual method solve(). There are four of them, to find the zero of a function. Solve() takes no argument and return the result of the method chosen.

There are also this files:

- SolverTraits collects the main types used by all classes

- SolverFactory provides a SolverBase resource

- Secant/ Bisection/ QuasiNewton/ Brent are all the methods used to find the zero

- data stores all the parameters used by the methods 

- SolverParams is a class that uses GetPot to obtain the parameters from the file data
 
**Notes**

To get the programm running, you have to change the directory in the Makefile. 

Calling `make exe` you can get the output results. 

To choose different parameters or the method, you can change the file data.
