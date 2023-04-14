#include "QuasiNewton.hpp"
#include <iostream>
#include <limits>
#include <cmath>
#include <functional>

using Function = SolverTraits::Function;
using ResultType = SolverTraits::ResultType;

// Computes the zero of a scalar function with the Newton
// It stops when \f$|f(x)|\le tol|f(a)| + tola
// The derivative is approximated with a central difference scheme
// Returns the approximation of the zero of fun if converging, if not returns a NaN and an error 
// a initial point  

// constructor
QuasiNewton::QuasiNewton(const Function &fun, ResultType a, ResultType b, const ResultType tol, const ResultType tola, unsigned int maxIt)
    : SolverBase(fun)
    , a(a) 
    , b(b) 
    , tol(tol)
    , tola(tola)
    , maxIt(maxIt) {}

ResultType QuasiNewton::solve() {
    ResultType		ya = fun(a);
    ResultType 		resid = std::abs(ya);
    unsigned int 	iter{0u};
    ResultType 		check = tol * resid + tola;
    bool 		goOn = resid > check;
    ResultType 		sol = std::numeric_limits<ResultType>::has_quiet_NaN;
    ResultType 		h = std::abs((b - a) / 100.);
    ResultType 		df;

    while (goOn && iter < maxIt) {
        ++iter;
        df = (fun(a + h) - fun(a - h)) / (2 * h);
        a += -ya / df;
        ya = fun(a);
        resid = std::abs(ya);
        goOn = resid > check;
    }

    if (iter < maxIt) 
    {
        sol = a;
    } 
    else 
    {
        std::cerr << "The method does not converge" << std::endl;
    } 

    return sol;
}
