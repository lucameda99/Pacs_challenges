//
// Created by Ema on 11/04/2023.
//

#include "Bisection.h"
#include "Traits.h"
namespace zerosolvers {

    Bisection::Bisection(Traits::ScalarFunction &f,
    Traits::scalar a,
    Traits::scalar b,
    Traits::scalar tol
    ) : m_f (f), m_a(a), m_b(b), m_tol(tol) {};

    Traits::ReturnType Bisection::solve() {
    double ya = m_f(m_a);
    double yb = m_f(m_b);
    double delta = m_b - m_a;
    // SURE_ASSERT(ya * yb < 0, "Function must change sign at the two end values");
    if (
    ya *yb
    > 0)
    return

    std::make_tuple(std::numeric_limits<Traits::scalar>::quiet_NaN(),

    false);
    double yc{ya};
    double c{m_a};
    while (
    std::abs(delta)
    > 2 * m_tol) {
    c = (m_a + m_b) / 2.;
    yc = m_f(c);
    if (
    yc *ya<
    0.0) {
    yb = yc;
    m_b = c;
}
else {
ya = yc;
m_a = c;
}
delta = m_b - m_a;
}
return
std::make_tuple((m_a
+ m_b) / 2., true);
}
}