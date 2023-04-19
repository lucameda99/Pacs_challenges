//
// Created by Ema on 19/04/2023.
//

#ifndef CHALLENGE2_UPDATE_BRENTSEARCH_H
#define CHALLENGE2_UPDATE_BRENTSEARCH_H


#include "BaseSolver.h"
#include "TypeTraits.h"

using ResultType = TypeTraits::ResultType;  //make the syntax lighter
using Real = TypeTraits::Real;
using ScalarFunction = TypeTraits::ScalarFunction;
using iterType = TypeTraits::iterType;

class BrentSearch : public BaseSolver{
public:
    BrentSearch(ScalarFunction &f, Real a, Real b, Real tol = 1.e-5,
                iterType maxIter = 200);
    [[nodiscard]] ResultType solve() const override;
private:
    ScalarFunction& m_f;
    Real m_a, m_b, m_tol;
    iterType m_maxIt;
};

BrentSearch::BrentSearch(ScalarFunction &f, Real a, Real b, Real tol,
                         iterType maxIter)
                         : m_f(f)
                         , m_a(a)
                         , m_b(b)
                         , m_tol(tol)
                         , m_maxIt(maxIter){}

ResultType BrentSearch::solve() const {

    Real a = m_a;
    Real b = m_b;

    auto ya = m_f(a);
    auto yb = m_f(b);
    // First check.
    if((ya * yb) >= 0.0){
        if(ya == 0.)
            return {a, true};
        else if(yb == 0.)
            return {b, true};
        else
            return {a, false}; // precondition not met
    };
    //
    if(std::abs(ya) < std::abs(yb))
    {
        std::swap(a, b);
        std::swap(ya, yb);
    }
    //
    auto     c = a;
    auto     d = c;
    auto     yc = ya;
    bool     mflag{true};
    auto     s = b;
    auto     ys = yb;
    unsigned iter{0u};
    do
    {
        //
        if(ya != yc and yb != yc)
        {
            auto yab = ya - yb;
            auto yac = ya - yc;
            auto ycb = yc - yb;
            // inverse quadratic interpolation
            s = a * ya * yc / (yab * yac) + b * ya * yc / (yab * ycb) -
                c * ya * yb / (yac * ycb);
        }
        else
        {
            // secant
            s = b - yb * (b - a) / (yb - ya);
        }
        //
        if(((s - 3 * (a + b) / 4) * (s - b) >= 0) or // condition 1
           (mflag and
            (std::abs(s - b) >= 0.5 * std::abs(b - c))) or // condition 2
           (!mflag and
            (std::abs(s - b) >= 0.5 * std::abs(c - d))) or // condition 3
           (mflag and (std::abs(b - c) < m_tol)) or          // condition 4
           (!mflag and (std::abs(c - d) < m_tol))            // condition 5
                )
        {
            mflag = true;
            s = 0.5 * (a + b); // back to bisection step
        }
        else
            mflag = false;
        //
        ys = m_f(s);
        d = c;
        c = b;
        yc = yb;
        //
        if(ya * ys < 0)
        {
            b = s;
            yb = ys;
        }
        else
        {
            a = s;
            ya = ys;
        }
        //
        if(std::abs(ya) < std::abs(yb))
        {
            std::swap(a, b);
            std::swap(ya, yb);
        }
        //
    }
    while(ys != 0. && std::abs(b - a) > m_tol && iter < m_maxIt);
    return {s, iter < m_maxIt};
}



#endif //CHALLENGE2_UPDATE_BRENTSEARCH_H
