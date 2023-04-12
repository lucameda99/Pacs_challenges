//
// Created by Ema on 12/04/2023.
//

#ifndef SOLVER_FACTORY_SINGLETON_TRAITS_H
#define SOLVER_FACTORY_SINGLETON_TRAITS_H


#include <memory>
#include <functional>

#include <concepts>
#include "BaseSolver.h"

class BaseSolver;

namespace zerosolvers{

    struct Traits {
        //using ID = std::string;
        //using Builder = std::function<std::unique_ptr<BaseSolver>()>;
        using scalar = double;
        using ReturnType = std::tuple<scalar, bool>;

        using ScalarFunction = std::function<scalar(scalar)>;
    };


}


#endif //SOLVER_FACTORY_SINGLETON_TRAITS_H
