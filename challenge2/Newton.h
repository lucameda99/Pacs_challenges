#ifndef CHALLENGE2_UPDATE_NEWTON_H
#define CHALLENGE2_UPDATE_NEWTON_H

#include "BaseSolver.h"
#include "TypeTraits.h"

/*!
* * Newton method solver: solves the non-linear function f(x) = 0 using the Newton method
*
 * @param m_a First end of initial interval
 * @param m_tol Tolerance
 * @param m_tola Absolute tolerance
 * @param m_maxIt Maximum number of iterations
 * @param m_df Derivative of the function
*/

using ResultType = TypeTraits::ResultType;  //make the syntax lighter
using Real = TypeTraits::Real;
using ScalarFunction = TypeTraits::ScalarFunction;
using iterType = TypeTraits::iterType;

class Newton : public BaseSolver{
public:
    Newton(const ScalarFunction &f, const ScalarFunction &df, Real a,
           Real tol = 1e-5, Real tola = 1e-10, iterType maxIt = 150);
    [[nodiscard]] ResultType solve() const override;
private:
    const ScalarFunction& m_df;
    Real m_a, m_tol, m_tola;
    iterType m_maxIt;
};

Newton::Newton(const ScalarFunction &f,const ScalarFunction &df,
               Real a, Real tol, Real tola, iterType maxIt)
               : BaseSolver(f)
               , m_df(df)
               , m_a(a)
               , m_tol(tol)
               , m_tola(tola)
               , m_maxIt(maxIt)
               {}

ResultType Newton::solve() const {

    Real a = m_a;

    Real ya = m_f(a);
    Real resid = std::abs(ya);
    iterType iter{0u};
    Real check = m_tol * resid + m_tola;
    bool goOn = resid > check;
    while (goOn && iter < m_maxIt) {
        ++iter;
        a += -ya / m_df(a);
        ya = m_f(a);
        resid = std::abs(ya);
        goOn = resid > check;
    }

    return std::make_tuple(a, (iter < m_maxIt));
}

#endif //CHALLENGE2_UPDATE_NEWTON_H
