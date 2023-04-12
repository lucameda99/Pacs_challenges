
#include "Regulafalsi.h"

#include "Secant.h"
#include "Traits.h"
#include <tuple>
#include <limits>

namespace zerosolvers {

    Regulafalsi::Regulafalsi(Traits::ScalarFunction &f,Traits::scalar a,Traits::scalar b,Traits::scalar tol):
    m_f (f), m_a(a), m_b(b), m_tol(tol), m_tola(1e-10){};

    Traits::ReturnType Regulafalsi::solve() {
        double ya = m_f(m_a);
        double yb = m_f(m_b);
        double delta = m_b - m_a;
        double resid0 = std::max(std::abs(ya), std::abs(yb));
//SURE_ASSERT(ya * yb < 0, "Function must change sign at the two end values");
        if (ya *yb > 0){
            return std::make_tuple(std::numeric_limits<Traits::scalar>::quiet_NaN(),false);}

        double           yc{ya};
        double           c{m_a};
        double           incr = std::numeric_limits<double>::max();
        constexpr double small = 10.0 * std::numeric_limits<double>::epsilon();
        while(std::abs(yc) > m_tol * resid0 + m_tola && incr > small)
        {
            double incra = -ya / (yb - ya);
            double incrb = 1. - incra;
            double incr = std::min(incra, incrb);
            if(!(std::max(incra, incrb) <= 1.0 && incr >= 0)) {
                return std::make_tuple(std::numeric_limits<Traits::scalar>::quiet_NaN(),false);}

            c = m_a + incra * delta;
            // std::cout << c << std::endl;
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
            /*
             *      std::cout << delta << " " << yc << " " << ya << " " << yb << " "
             * << incr
             *      << std::endl;
             */
        }
        return std::make_tuple(c,true);
    }
}