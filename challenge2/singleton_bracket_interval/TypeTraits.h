//
// Created by Ema on 13/04/2023.
//


#ifndef CHALLENGE2_UPDATE_TYPETRAITS_H
#define CHALLENGE2_UPDATE_TYPETRAITS_H
#include "extendedAssert.hpp"

namespace TypeTraits {

    using ResultType = std::tuple<double, bool>;    //so that it works for BracketInterval too
    using ID = std::string;
    //using Builder =  std::function<std::shared_ptr<BaseSolver>()>
    using Real = double;
    using ScalarFunction = std::function<double(double)>;
    using iterType = unsigned int;
}

#endif //CHALLENGE2_UPDATE_TYPETRAITS_H
