
#include <iostream>
#include <cmath>

#include "SolverFactory.h"

int main() {

    TypeTraits::ScalarFunction F = [] (double x){return 0.5 - exp(M_PI*x); };
    TypeTraits::ScalarFunction dF = [] (double x){return -M_PI*exp(M_PI*x); };
    //exact result:
    Real root = 1/M_PI* log(0.5);
    std::cout << "\n\t Exact result = " << root << std::endl;

    // Instantiating SolverFactory
    auto & factory = SolverFactory::Instance();

    Real a = -1, b = 0, tol = 1e-5;
    // adding the bisection solver to the factory
    factory.addSolver<Bisection>("bisection", F, a, b);
    // adding Newton method
    factory.addSolver<Newton>("newton", F, dF, a, b);
    // adding RegulaFalsi method
    factory.addSolver<RegulaFalsi>("regulafalsi", F, a, b);
    // adding Secant method
    factory.addSolver<Secant>("secant", F, a, b);
    // adding BracketInterval method
    // factory.addSolver<BracketInterval>("bracketinterval", F, a);
    // adding BrentSearch method
    factory.addSolver<BrentSearch>("brentsearch", F, a, b);

    //___SOLVE___

    // solving with bisection method
    auto solver = factory.selectSolver("bisection");
    if (!solver) {return 0;}
    std::cout << "\n\t bisection: "<< std::get<0>(solver->solve()) << std::endl;
    //todo: print the output with the correct number of decimal digits

    // solving with newton method
    solver = factory.selectSolver("newton");
    if (!solver) {return 0;}
    ResultType result = solver->solve();
    std::cout << "\n\t newton: "<< std::get<0>(result) << ", converged: " << std::get<1>(result) << std::endl;

    // solving with regulafalsi method
    solver = factory.selectSolver("regulafalsi");
    if (!solver) {return 0;}
    std::cout << "\n\t regulafalsi: "<< std::get<0>(solver->solve()) << std::endl;

    // solving with secant method
    solver = factory.selectSolver("secant");
    if (!solver) {return 0;}
    result = solver->solve();
    std::cout << "\n\t secant: "<< std::get<0>(result) << ", converged: " << std::get<1>(result) << std::endl;

    // solving with Brentsearch method
    solver = factory.selectSolver("brentsearch");
    if (!solver) {return 0;}
    result = solver->solve();
    std::cout << "\n\t brentsearch: "<< std::get<0>(result) << ", converged: " << std::get<1>(result) << std::endl;



    // selecting a non-existent solver
    solver = factory.selectSolver("bisection_method");
    if (!solver) {return 0;}
    solver->solve(); // solving with bisection

    std::cout << "Hello, World!" << std::endl;
    return 0;
}