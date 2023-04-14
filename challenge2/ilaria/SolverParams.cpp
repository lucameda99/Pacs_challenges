#include "SolverParams.hpp"
#include "GetPot"

SolverParams::SolverParams(const std::string &filename){
    
    GetPot file(filename);
    
    // Get values from the filename file. If not found, assign the second one in the parentesis.	
    a = file("a", -1.);
    b = file("b", 1.);

    tol = file("tol", 1e-5);
    tola = file("tola", 1e-10);
    maxIt = file("maxIt", 200);

    name = file("name", "QuasiNewton");

}
