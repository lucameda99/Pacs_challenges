//
// Created by Ema on 16/04/2023.
//

#ifndef CHALLENGE2_UPDATE_NEWTON_H
#define CHALLENGE2_UPDATE_NEWTON_H

#include "BaseSolver.h"
#include "TypeTraits.h"

using ResultType = TypeTraits::ResultType;  //make the syntax lighter
using Real = TypeTraits::Real;
using ScalarFunction = TypeTraits::ScalarFunction;

class Newton : public BaseSolver{
public:
    Newton(ScalarFunction &f, Real a, Real b, Real tol = 1e-5);
    [[nodiscard]] ResultType solve() const override;
private:
    ScalarFunction& m_f, m_df;
    Real m_a, m_b, m_tol;
};

ResultType Newton::solve() const {

    std::tuple<double, bool>
    Newton(Function const &f, Dfunction const & df, double a, double tol = 1e-4,
           double tola = 1.e-10, unsigned int maxIt = 150)
    {
        double       ya = f(a);
        double       resid = std::abs(ya);
        unsigned int iter{0u};
        double       check = tol * resid + tola;
        bool         goOn = resid > check;
        while(goOn && iter < maxIt)
        {
            ++iter;
            a += - ya/df(a);
            ya = f(a);
            resid = std::abs(ya);
            goOn = resid > check;
        }

        return std::make_tuple(a, (iter < maxIt));
    }

Newton::Newton(ScalarFunction &f, Real a, Real b, Real tol) : m_f(f), m_a(a), m_b(b), m_tol(tol) {}

#endif //CHALLENGE2_UPDATE_NEWTON_H
