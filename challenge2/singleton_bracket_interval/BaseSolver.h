//
// Created by Ema on 13/04/2023.
//

#ifndef CHALLENGE2_UPDATE_BASESOLVER_H
#define CHALLENGE2_UPDATE_BASESOLVER_H

#include "TypeTraits.h"

using ResultType = TypeTraits::ResultType;
using ScalarFunction = TypeTraits::ScalarFunction;

class BaseSolver {
    protected:
        ScalarFunction m_f;

    public:
        BaseSolver(const ScalarFunction &f);
        virtual ~BaseSolver() {}
        virtual ResultType solve() const = 0;
};

BaseSolver::BaseSolver(const ScalarFunction &f) : m_f(f) {}
#endif //CHALLENGE2_UPDATE_BASESOLVER_H