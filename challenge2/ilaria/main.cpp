#include <iostream>
#include <functional>
#include <cmath>
#include <memory>
#include "SolverFactory.hpp"
#include "SolverParams.hpp"

using Function = SolverTraits::Function;
using ResultType = SolverTraits::ResultType;

int main() {
    // function of which we want to find the zero
    const Function F = [] (double x){return 0.5 - exp(M_PI*x); };

    SolverFactory factory; //SolverFactory object

    // use the call operator of the SolverFactory class
    // solver is a pointer to the derived class associated to the chosen method
    std::unique_ptr<SolverBase> solver = (factory) ("data", F);

    // res is the approximation of the zero of F
    const ResultType res = solver->solve(); 
    
    SolverParams params("data");		
    std::cout << "The approximated result, obtained with the " << params.name << " method, is: "<< res << std::endl;

    return 0;
}