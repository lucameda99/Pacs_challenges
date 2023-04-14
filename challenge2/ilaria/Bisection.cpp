#include "Bisection.hpp"
#include "extendedAssert.hpp"

using Function = SolverTraits::Function;
using ResultType = SolverTraits::ResultType;

// Computes the zero of a scalar function with the method of the bisection
// The returned value is far from the zero at most the given tolerance

// constructor
Bisection::Bisection(const Function &fun, ResultType a, ResultType b, const ResultType tol)
    : SolverBase(fun)
    , a(a)
    , b(b)
    , tol(tol) {}
    
ResultType Bisection::solve() {
    ResultType	 ya = fun(a);
    ResultType	 yb = fun(b);
    ResultType 	 delta = b - a;
    SURE_ASSERT(ya * yb < 0, "Function must change sign at the two end values");
    ResultType 	 yc{ya};
    ResultType   c{a};
    
    while(std::abs(delta) > 2 * tol)
    {
        c = (a + b) / 2.;
        yc = fun(c);
        if(yc * ya < 0.0)
        {
            yb = yc;
            b = c;
        }
        else
        {
            ya = yc;
            a = c;
        }
        delta = b - a;
    }
    return (a + b) / 2.;
   
}
