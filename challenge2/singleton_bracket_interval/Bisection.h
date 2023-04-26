//
// Created by Ema on 13/04/2023.
//

#ifndef CHALLENGE2_UPDATE_BISECTION_H
#define CHALLENGE2_UPDATE_BISECTION_H

#include "BaseSolver.h"
#include "TypeTraits.h"

using ResultType = TypeTraits::ResultType;  //make the syntax lighter
using Real = TypeTraits::Real;
using ScalarFunction = TypeTraits::ScalarFunction;

class Bisection : public BaseSolver{
public:
    Bisection(const ScalarFunction &f, Real a, Real b, Real tol = 1e-5);
    [[nodiscard]] ResultType solve() const override;
private:
    Real m_a, m_b, m_tol;
};

Bisection::Bisection(const ScalarFunction &f, Real a, Real b, Real tol) : BaseSolver(f), m_a(a), m_b(b), m_tol(tol) {}

ResultType Bisection::solve() const {

    Real a = m_a;
    Real b = m_b;

    Real ya = m_f(a);
    Real yb = m_f(b);

    Real delta = b - a;
    SURE_ASSERT(ya * yb < 0, "Function must change sign at the two end values");
    Real yc{ya};
    Real c{a};
    while(std::abs(delta) > 2 * m_tol)
    {
        c = (a + b) / 2.;
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
    }
    return std::make_tuple((a + b)/2., true);
}
#endif //CHALLENGE2_UPDATE_BISECTION_H