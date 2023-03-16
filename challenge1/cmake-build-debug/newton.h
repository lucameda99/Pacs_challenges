//
// Created by Ema on 14/03/2023.
//

#ifndef CHALLENGE1_NEWTON_H
#define CHALLENGE1_NEWTON_H


#include <functional>
#include <limits>
class NewtonSolver{
public:
//protected:    // we don't need it since we don't have inheritance
    NewtonSolver(const std::function<double(double)> &f,
                 const std::function<double(double)> &df,
                 double tol_res = std::numeric_limits<double>::epsilon()*1000.0,
                 double tol_incr = std::numeric_limits<double>::epsilon()*1000.0,
                 unsigned int maxit = 100)
            : m_f(f)    //define constant attributes in the constructor
            , m_df(df)
            , m_tol_res(tol_res)
            , m_tol_incr(tol_incr)
            , m_maxit(maxit)
            , m_x(0)
            , m_dfx(0)
            , m_res(0)
            , m_iter(0)
    {}

    void
    solve(double x0)
    {
        //implement newton
        m_x = x0;
        for(m_iter = 0; m_iter < m_maxit; m_iter++){
            m_res = m_f(m_x);
            if(std::abs(m_res) < m_tol_res)
                break;
            m_dfx = m_df(m_x);
            m_dx = m_res / m_dfx;
            m_x -= m_dx;
            if(std::abs(m_dx) < m_tol_incr)
                break;
        }
    }
    double get_result() const{return m_x;}
    unsigned int get_iter() const{return m_iter;}

private:
    const std::function<double(double)> m_f;    //good practice. specify that a variable is a member of the class by adding "m_" before its name
    const std::function<double(double)> m_df;
    const double m_tol_res;
    const double m_tol_incr;
    const unsigned int m_maxit;

    double m_x;
    double m_dfx;
    double m_dx;    //current increment
    double m_res;
    unsigned int m_iter;
};

#endif //CHALLENGE1_NEWTON_H
