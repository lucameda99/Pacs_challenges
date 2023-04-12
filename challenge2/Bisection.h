//
// Created by Ema on 11/04/2023.
//

#ifndef SOLVER_FACTORY_SINGLETON_BISECTION_H
#define SOLVER_FACTORY_SINGLETON_BISECTION_H

#include "BaseSolver.h"
#include "Traits.h"

#include <limits>
#include <tuple>

namespace zerosolvers {

    class Bisection final: public BaseSolver {

    public:
        Traits::ScalarFunction m_f;
        Traits::scalar m_a;
        Traits::scalar m_b;
        Traits::scalar m_tol;


        Bisection(Traits::ScalarFunction &f,Traits::scalar a,Traits::scalar b,Traits::scalar tol);

        Traits::ReturnType solve() override;


    };

}
#endif //SOLVER_FACTORY_SINGLETON_BISECTION_H
