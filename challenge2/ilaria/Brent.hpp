#ifndef BRENT_HPP
#define BRENT_HPP

#include "SolverBase.hpp"

class Brent:public SolverBase{
public:
    //constructor
    Brent(const Function &fun, ResultType a, ResultType b, const ResultType tol, const unsigned int maxIter); 
    
    ResultType solve() override;

private:
    ResultType a;
    ResultType b;
    ResultType tol;
    unsigned int maxIter;
};

#endif //BRENT_HPP
