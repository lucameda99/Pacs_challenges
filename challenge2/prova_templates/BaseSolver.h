//
// Created by Ema on 13/04/2023.
//

#ifndef CHALLENGE2_UPDATE_TEMPLATE_CLASSES_BASESOLVER_H
#define CHALLENGE2_UPDATE_TEMPLATE_CLASSES_BASESOLVER_H


#include "TypeTraits.h"

using ResultType = TypeTraits::ResultType;

//todo: instead of a general typename here add the concept!!
template <typename Function>
class BaseSolver {
public:
    virtual ~BaseSolver() {}
    virtual ResultType solve(Function f) = 0;
};
#endif //CHALLENGE2_UPDATE_TEMPLATE_CLASSES_BASESOLVER_H
