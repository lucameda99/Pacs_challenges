//
// Created by Ema on 11/04/2023.
//

#ifndef SOLVER_FACTORY_SINGLETON_BASESOLVER_H
#define SOLVER_FACTORY_SINGLETON_BASESOLVER_H
#include <iostream>

#include "Traits.h"

class BaseSolver {
private:

public:
    BaseSolver() = default;
    virtual ~BaseSolver() {}

    Traits::ReturnType solve() const = 0;
};


#endif //SOLVER_FACTORY_SINGLETON_BASESOLVER_H
