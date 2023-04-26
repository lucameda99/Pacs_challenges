#ifndef CHALLENGE2_UPDATE_SECANT_H
#define CHALLENGE2_UPDATE_SECANT_H

#include "BaseSolver.h"
#include "TypeTraits.h"

/*!
* * Secant method solver: solves the non-linear function f(x) = 0 using the Secant method
*
 * @param a: left end of the interval
 * @param b: right end of the interval
 * @param tol: tolerance on the function value
 * @param tola: tolerance on the interval
 * @param maxIt: maximum number of iterations
*/

using ResultType = TypeTraits::ResultType;  //make the syntax lighter
using Real = TypeTraits::Real;
using ScalarFunction = TypeTraits::ScalarFunction;

class Secant : public BaseSolver{
public:
    Secant(const ScalarFunction &f, Real a, Real b,
           Real tol = 1e-5, Real tola = 1e-10, unsigned int maxIt = 150);
    [[nodiscard]] ResultType solve() const override;
private:
    Real m_a, m_b, m_tol, m_tola, m_maxIt;
};

Secant::Secant(const ScalarFunction &f,
               Real a, Real b, Real tol, Real tola, unsigned int maxIt)
        : BaseSolver(f)
        , m_a(a)
        , m_b(b)
        , m_tol(tol)
        , m_tola(tola)
        , m_maxIt(maxIt)
{}

ResultType Secant::solve() const {

    Real a = m_a;

    Real ya = m_f(a);
    Real resid = std::abs(ya);
    Real c{a};
    unsigned int iter{0u};
    Real check = m_tol * resid + m_tola;
    bool goOn = resid > check;
    while (goOn && iter < m_maxIt) {
        ++iter;
        Real yb = m_f(m_b);
        c = a - ya * (m_b - a) / (yb - ya);
        Real yc = m_f(c);
        resid = std::abs(yc);
        goOn = resid > check;
        ya = yc;
        a = c;
    }
    return std::make_tuple(c, (iter < m_maxIt));
}
#endif //CHALLENGE2_UPDATE_SECANT_H
