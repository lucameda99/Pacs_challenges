#ifndef BISECTION_HPP
#define BISECTION_HPP

#include "SolverBase.hpp"

class Bisection:public SolverBase{
public:
    // constructor	
    Bisection(const Function &fun, ResultType a, ResultType b, const ResultType tol); 

    ResultType solve() override;

private:
    ResultType a;
    ResultType b;
    ResultType tol;
};


#endif //BISECTION_HPP
