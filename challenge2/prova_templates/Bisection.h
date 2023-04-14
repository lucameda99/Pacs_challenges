//
// Created by Ema on 13/04/2023.
//

#ifndef CHALLENGE2_UPDATE_TEMPLATE_CLASSES_BISECTION_H
#define CHALLENGE2_UPDATE_TEMPLATE_CLASSES_BISECTION_H


#include "BaseSolver.h"
#include "TypeTraits.h"

using ResultType = TypeTraits::ResultType;  //make the syntax lighter
using Real = TypeTraits::Real;

template <typename Function>
class Bisection : public BaseSolver<Function>{
public:
    virtual ResultType solve(Function f) override;
    /*
     * the class is not supposed to have private members. You first create the object (empty)
     * and then every time you call solve() you must specify all the parameters
     * */
};
//____________END_OF_CLASS___________

template<typename Function>
ResultType Bisection<Function>::solve(Function f) {
    return 0;
}

#endif //CHALLENGE2_UPDATE_TEMPLATE_CLASSES_BISECTION_H
