#include "Secant.hpp"
#include <iostream>
#include <limits>
#include <cmath>

using Function = SolverTraits::Function;
using ResultType = SolverTraits::ResultType;

// Computes the zero of a scalar function with the method of the secant
// It stops when \f$|f(x)|\le tol|f(a)| + tola
// Returns the approximation of the zero of fun if converging, if not returns a NaN and an error
// a first point for computing derivatives
// b second point for computing derivatives

// constructor
Secant::Secant(const Function &fun, ResultType a, ResultType b, const ResultType tol, const ResultType tola, unsigned int maxIt)
    : SolverBase(fun)
    , a(a)
    , b(b)
    , tol(tol)
    , tola(tola)
    , maxIt(maxIt) {}
    
ResultType Secant::solve() {
    ResultType       ya = fun(a);
    ResultType       resid = std::abs(ya);
    ResultType       c{a};
    ResultType       sol = std::numeric_limits<ResultType>::has_quiet_NaN;
    unsigned int     iter{0u};
    ResultType       check = tol * resid + tola;
    bool             goOn = resid > check;
    while(goOn && iter < maxIt)
    {
        ++iter;
        ResultType yb = fun(b);
        c = a - ya * (b - a) / (yb - ya);
        ResultType yc = fun(c);
        resid = std::abs(yc);
        goOn = resid > check;
        ya = yc;
        a = c;
    }
    if (iter <= maxIt) 
        {
        sol = c;
        }
    else 
        {
        std::cerr << "The method does not converge" << std::endl; //NaN
        } 
        
    return sol;
}
