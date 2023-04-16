
#include <iostream>
#include <cmath>

#include "SolverFactory.h"

int main() {

    TypeTraits::ScalarFunction F = [] (double x){return 0.5 - exp(M_PI*x); };
    //exact result:
    Real root = 1/M_PI* log(0.5);
    std::cout << "\n\t Exact zero = " << root << std::endl;

    // Instantiating SolverFactory
    auto & factory = SolverFactory::Instance();

    // adding the bisection solver to the factory
    factory.addSolver<Bisection>("bisection", F, -1, 0, 1e-5);

    // solving with bisection method
    auto solver = factory.selectSolver("bisection");
    if (!solver) {return 0;}
    std::cout << "\n\t bisection: "<<solver->solve() << std::endl;
    //todo: print the output with the correct number of decimal digits

    // selecting a non-existent solver
    solver = factory.selectSolver("bisection_method");
    if (!solver) {return 0;}
    solver->solve(); // solving with bisection

    std::cout << "Hello, World!" << std::endl;
    return 0;
}