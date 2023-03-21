//
// Created by Ema on 12/03/2023.
//

#ifndef CHALLENGE1_ODESOLVER_H
#define CHALLENGE1_ODESOLVER_H

#include <vector>
#include <functional>

using std::vector;

class ODEsolver {
private:
    const double m_y0, m_T;
    const unsigned int m_N;
    double m_h;
    vector<double> m_t, m_u;
    std::function<double(double, double)> m_f;
    // std::function<double(double, double)> m_fprime;

public:
    // Constructor
    ODEsolver(
            std::function<double(double,double)> f
            //, std::function<double(double, double)> fprime
            , double y0
            , double T
            , unsigned int N);

    // Solve method
    void solveCN(void);

    // Getters
    [[nodiscard("return value of getT discarded!")]] const vector<double> &getT() const;

    [[nodiscard("return value of getU discarded!")]] const vector<double> &getU() const;
};


#endif //CHALLENGE1_ODESOLVER_H
