
#ifndef CHALLENGE1_ODESOLVER_H
#define CHALLENGE1_ODESOLVER_H

#include <vector>
#include <functional>

#include "Derivatives.hpp"
#include "basicZeroFun.hpp"

using std::vector;

class ODEsolver {
private:
    const std::function<double(double, double)> m_f;
    const double m_y0, m_T;
    const unsigned int m_N;
    const double m_theta = 0.5;
    double m_h;
    vector<double> m_t, m_u;
    // std::function<double(double, double)> m_fprime;  //deprecated
public:
    // Constructor
    ODEsolver(const std::function<double(const double&, const double&)> f
            // , std::function<double(double, double)> f_prime
            , const double y0
            , const double T
            , const unsigned int N
            , const double theta)
            : m_f(f)
            // , m_fprime(f_prime)
            , m_y0(y0)
            , m_T(T)
            , m_N(N)
            , m_theta(theta)
    {
        m_h = (m_T/static_cast<double>(m_N));

        m_u.reserve(N+1);
        m_u.emplace_back(m_y0);

        m_t.reserve(N+1);
        //build the vector of times in here
        for (size_t i=0; i<m_N+1; ++i)
            m_t.emplace_back(i*m_h);

        // for debug purposes
        /*
         std::cout << "\n\t constructor ODEsolver: " <<
        "\n\t m_f: " << f << std::endl;
         */
    }

    // Solve method
    void solveCN(void) {
        // solve using crank nicolson
        for (unsigned int i = 0; i < m_N; ++i) {
            double t_n = m_t[i];
            double t_np1 = m_t[i + 1];
            // auto F = [&](double x){return x - m_h/2*(m_f(t_np1,x)+m_f(t_n,m_u[i]))-m_u[i];};
            auto F = [&](double x) {
                return x - m_theta * m_h * m_f(t_np1, x) - (1 - m_theta) * m_h * m_f(t_n, m_u[i]) - m_u[i];
            };

            // auto Fprime = [&](double x){ return 1 - (m_h/2)*m_fprime(t_np1,x); };
            auto Fprime = apsc::makeForwardDerivative<1>(F, m_h);

            // std::tuple<double, bool>
            // Newton(Function const &f, Dfunction const & df, double a, double tol = 1e-4,
            //       double tola = 1.e-10, unsigned int maxIt = 150)
            std::tuple<double, bool> temp;
            temp = apsc::Newton(F, Fprime, m_u[i]);
            // m_u[i+1] = std::get<0>(temp);
            m_u.emplace_back(std::get<0>(temp));
        }
    }
    // Getters
    [[nodiscard("return value of getT discarded!")]] const vector<double> &getT() const{
        return m_t;
    }

    [[nodiscard("return value of getU discarded!")]] const vector<double> &getU() const{
        return m_u;
    }
};


#endif //CHALLENGE1_ODESOLVER_H
