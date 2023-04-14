#ifndef QUASINEWTON_HPP
#define QUASINEWTON_HPP

#include "SolverBase.hpp"

class QuasiNewton:public SolverBase {
public:
    //constructor
    QuasiNewton(const Function &fun, ResultType a, ResultType b, const ResultType tol, const ResultType tola, unsigned int maxIt); 

    ResultType solve() override; 
    
private:
    ResultType a;
    ResultType b;
    ResultType tol;
    ResultType tola;
    unsigned int maxIt;
};

#endif //QUASINEWTON_HPP
