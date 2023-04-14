#include "SolverFactory.hpp"
#include "SolverParams.hpp"
#include "Secant.hpp"
#include "QuasiNewton.hpp"
#include "Bisection.hpp"
#include "Brent.hpp"
#include <memory>
#include <iostream>

// call operator
std::unique_ptr<SolverBase>
SolverFactory::operator()(const std::string &filename, const Function &fun){

    // object of the class SolverParams with the parameters, stored in filename
    SolverParams params(filename);

    std::string SolverName = params.name;

    if(SolverName == "Secant")
        return std::make_unique<Secant>(fun,
                                        params.a,
                                        params.b,
                                        params.tol,
                                        params.tola,
                                        params.maxIt);

    else if(SolverName == "QuasiNewton")
        return std::make_unique<QuasiNewton>(fun,
                                             params.a,
                                             params.b,
                                             params.tol,
                                             params.tola,
                                             params.maxIt);

    else if(SolverName == "Bisection")
        return std::make_unique<Bisection>(fun,
                                           params.a,
                                           params.b,
                                           params.tol);
                                           
    else if(SolverName == "Brent")
        return std::make_unique<Brent>(fun,
                                       params.a,
                                       params.b,
                                       params.tol,
                                       params.maxIt);                                       
                                           
    else 
    	return std::unique_ptr<SolverBase>(nullptr); // returns a null pointer if I try to use a non existent method                                    
}

