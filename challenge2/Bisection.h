//
// Created by Ema on 11/04/2023.
//

#ifndef SOLVER_FACTORY_SINGLETON_BISECTION_H
#define SOLVER_FACTORY_SINGLETON_BISECTION_H

#include "BaseSolver.h"
#include "Traits.h"

#include <limits>
#include <tuple>

// template <Traits::ScalarFunction Function>
class Bisection : public BaseSolver{
private:
    Traits::ScalarFunction &m_f;
    Traits::scalar m_a;
    Traits::scalar m_b;
    Traits::scalar m_tol;
public:

    Bisection(Traits::ScalarFunction &f,
              Traits::scalar a,
              Traits::scalar b,
              Traits::scalar tol = 1.e-5) : m_f(f), m_a(a), m_b(b), m_tol(tol) {}

    /*!
     * Computes the zero of a scalar function with the method of the bisection
     * The returned value is far from the zero at most the given tolerance;
     *
     * @tparam Function
     * @param f The function
     * @param a First end of initial interval
     * @param b Second end of initial interval
     * @param tol Tolerance
     * @return The approximation of the zero of f
     * @pre f(a)*f(b)<0
     * @note It the interval brackets the zero convergence should be guaranteed.
     *
     */

    Traits::ReturnType
    solve()
    {
        double ya = m_f(m_a);
        double yb = m_f(m_b);
        double delta = m_b - m_a;
        // SURE_ASSERT(ya * yb < 0, "Function must change sign at the two end values");
        if (ya * yb > 0)
            return std::make_tuple(std::numeric_limits<Traits::scalar>::quiet_NaN(), false);
        double yc{ya};
        double c{m_a};
        while(std::abs(delta) > 2 * m_tol)
        {
            c = (m_a + m_b) / 2.;
            yc = m_f(c);
            if(yc * ya < 0.0)
            {
                yb = yc;
                m_b = c;
            }
            else
            {
                ya = yc;
                m_a = c;
            }
            delta = m_b - m_a;
        }
        return std::make_tuple((m_a + m_b) / 2., true);
    }

    Bisection();
};


#endif //SOLVER_FACTORY_SINGLETON_BISECTION_H
