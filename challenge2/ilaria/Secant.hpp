#ifndef SECANT_HPP
#define SECANT_HPP

#include "SolverBase.hpp"

class Secant:public SolverBase {
public:
    // constructor
    Secant(const Function &fun, ResultType a, ResultType b, const ResultType tol, const ResultType tola, unsigned int maxIt); 

    ResultType solve() override; 
    
private:
    ResultType a;
    ResultType b;
    ResultType tol;
    ResultType tola;
    unsigned int maxIt;
};

#endif //SECANT_HPP
