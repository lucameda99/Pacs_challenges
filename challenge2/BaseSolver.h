//
// Created by Ema on 11/04/2023.
//

#ifndef SOLVER_FACTORY_SINGLETON_BASESOLVER_H
#define SOLVER_FACTORY_SINGLETON_BASESOLVER_H
#include <iostream>

#include "Traits.h"
namespace zerosolvers {

    class BaseSolver {


    public:
        BaseSolver() = default;

        virtual ~BaseSolver() {}

        virtual Traits::ReturnType solve() = 0;
    };
}

#endif //SOLVER_FACTORY_SINGLETON_BASESOLVER_H
