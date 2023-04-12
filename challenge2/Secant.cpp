//
// Created by BARBARA on 12/04/2023.
//

#include "Secant.h"
#include "Traits.h"
#include <tuple>

namespace zerosolvers {

    Secant::Secant(Traits::ScalarFunction &f,Traits::scalar a,Traits::scalar b,Traits::scalar tol):
    m_f (f), m_a(a), m_b(b), m_tol(tol), m_tola(1e-10),m_maxIt(150){};

    Traits::ReturnType Secant::solve() {
    double ya = m_f(m_a);
    double resid = std::abs(ya);
    double c{m_a};
    unsigned int iter{0u};
    double check = m_tol * resid + m_tola;
    bool goOn = resid > check;
    while(
    goOn &&iter<m_maxIt
    ) {
    ++
    iter;
    double yb = m_f(m_b);
    c = m_a - ya * (m_b - m_a) / (yb - ya);
    double yc = m_f(c);
    resid = std::abs(yc);
    goOn = resid > check;
    ya = yc;
    m_a = c;
}

return std::make_tuple(c, (iter<m_maxIt));

}
}