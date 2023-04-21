#ifndef CHALLENGE2_UPDATE_QUASINEWTON_H
#define CHALLENGE2_UPDATE_QUASINEWTON_H

#include "BaseSolver.h"
#include "TypeTraits.h"

using ResultType = TypeTraits::ResultType;  //make the syntax lighter
using Real = TypeTraits::Real;
using ScalarFunction = TypeTraits::ScalarFunction;
using iterType = TypeTraits::iterType;

class QuasiNewton : public BaseSolver{
public:
    QuasiNewton(const ScalarFunction &f, Real a,Real b,
           Real tol = 1e-5, Real tola = 1e-10, iterType maxIt = 150);
    [[nodiscard]] ResultType solve() const override;
private:

    Real m_a,m_b, m_tol, m_tola;
    iterType m_maxIt;
};

QuasiNewton::QuasiNewton(const ScalarFunction &f,
               Real a,Real b,Real tol, Real tola, iterType maxIt)
        : BaseSolver(f)
        , m_df(df)
        , m_a(a)
        , m_tol(tol)
        , m_tola(tola)
        , m_maxIt(maxIt)
{}

ResultType QuasiNewton::solve() const {
    Real		ya = fun(a);
    Real 		resid = std::abs(ya);
    itertype 	iter{0u};
    Real 		check = tol * resid + tola;
    bool 		goOn = resid > check;
    Real 		sol = std::numeric_limits<Real>::has_quiet_NaN;
    Real 		h = std::abs((b - a) / 100.);
    Real		df;

    while (goOn && iter < maxIt) {
        ++iter;
        df = (fun(a + h) - fun(a - h)) / (2 * h);
        a += -ya / df;
        ya = fun(a);
        resid = std::abs(ya);
        goOn = resid > check;
    }

    return std::make_tuple(a, (iter < m_maxIt));
};


#endif //CHALLENGE2_UPDATE_QUASINEWTON_H
