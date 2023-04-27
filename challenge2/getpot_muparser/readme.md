# Project developed by Emanuele Tamburini and Luca Meda

For this second challenge we have built an Object Factory `FactorySolver.hpp` that gathers together different nonlinear solvers. These solvers apply to any nonlinear function $f:\mathbb{R}\mapsto\mathbb{R}$.

The factory has been implemented exploiting an `std::unordered_map`, which collects objects derived from the abstract class `BaseSolver.hpp`. Moreover, the factory is defined as a singleton to avoid different solvers to be spread in different facotries.
Every solver is implemented with a class that is derived from `BaseSolver.hpp`, therefore every solver calls the constructor of the parent class and define its own additional private datamembers too.
The file `TypeTraits.hpp` collects all the variable types used in the project, so that they can be modified with ease, without touching the implementation of every class.
Finally, in the `main.cpp` file, an example usage of the facotry is proposed, in which we show how to add solvers to te facotry and to use it to solve a nonlinear function. In the main file we read the function F and its derivative from a text file `data.txt`.  In addition, within the main file, the function `bracketInterval` may help the user to build the interval $[a,b]$ that is then passed to the solvers.