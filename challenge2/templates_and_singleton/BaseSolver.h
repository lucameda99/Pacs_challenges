//
// Created by Ema on 13/04/2023.
//

#ifndef CHALLENGE2_UPDATE_BASESOLVER_H
#define CHALLENGE2_UPDATE_BASESOLVER_H

#include "TypeTraits.h"

using ResultType = TypeTraits::ResultType;

class BaseSolver {

public:
    virtual ~BaseSolver() {}
    virtual ResultType solve() const = 0;
};

#endif //CHALLENGE2_UPDATE_BASESOLVER_H