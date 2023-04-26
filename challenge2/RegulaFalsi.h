
#ifndef CHALLENGE2_UPDATE_REGULAFALSI_H
#define CHALLENGE2_UPDATE_REGULAFALSI_H

#include <algorithm>
#include "BaseSolver.h"
#include "TypeTraits.h"

/*!
* * RegulaFalsi method solver: solves the non-linear function f(x) = 0 using the RegulaFalsi method
 *
 * @param a: left end of the interval
 * @param b: right end of the interval
 * @param tol: tolerance on the function value
 * @param tola: tolerance on the interval
*/

using ResultType = TypeTraits::ResultType;  //make the syntax lighter
using Real = TypeTraits::Real;
using ScalarFunction = TypeTraits::ScalarFunction;

class RegulaFalsi : public BaseSolver{
public:
    RegulaFalsi(const ScalarFunction &f, Real a, Real b, Real tol = 1e-5, Real tola = 1e-10);
    [[nodiscard]] ResultType solve() const override;
private:
    Real m_a, m_b, m_tol, m_tola;
};

RegulaFalsi::RegulaFalsi(const ScalarFunction &f, Real a, Real b,
                         Real tol, Real tola)
                         : BaseSolver(f), m_a(a), m_b(b)
                         , m_tol(tol), m_tola(tola){}

ResultType RegulaFalsi::solve() const {

    Real a = m_a;
    Real b = m_b;

    Real ya = m_f(a);
    Real yb = m_f(b);
    Real delta = b - a;
    Real resid0 = std::max(std::abs(ya), std::abs(yb));
    SURE_ASSERT(ya * yb < 0, "Function must change sign at the two end values");
    Real           yc{ya};
    Real           c{a};
    Real           incr = std::numeric_limits<Real>::max();
    constexpr Real small = 10.0 * std::numeric_limits<Real>::epsilon();
    while(std::abs(yc) > m_tol * resid0 + m_tola && incr > small)
    {
        Real incra = -ya / (yb - ya);
        Real incrb = 1. - incra;
        Real incr = std::min(incra, incrb);
        ASSERTM((std::max(incra, incrb) <= 1.0 && incr >= 0), "Chord is failing")
        c = a + incra * delta;
        // std::cout << c << std::endl;
        yc = m_f(c);
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
        /*
         *      std::cout << delta << " " << yc << " " << ya << " " << yb << " "
         * << incr
         *      << std::endl;
         */
    }
    return std::make_tuple(c, true);
}

#endif //CHALLENGE2_UPDATE_REGULAFALSI_H
