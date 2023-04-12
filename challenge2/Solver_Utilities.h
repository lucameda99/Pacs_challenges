#ifndef CHALLENGE_2_SOLVER_UTILITIES_H
#define CHALLENGE_2_SOLVER_UTILITIES_H
#include <memory>
#include<functional>
#include "BaseSolver.h"
#include "Bisection.h"
#include "Secant.h"
#include "Regulafalsi.h"


namespace zerosolvers
{

    template<typename ...Args>
    std::unique_ptr<BaseSolver>
    createSolver(std::string const &name, Args&& ...args)
    {

        if(name == "Bisection")
            return std::make_unique<Bisection>(std::forward<Args>(args)...);
        if(name == "Secant")
            return std::make_unique<Secant>(std::forward<Args>(args)...);
        if(name == "Regulafalsi")
            return std::make_unique<Regulafalsi>(std::forward<Args>(args)...);
        // this way I can easily check if I try to construct a non existent Polygon
        return std::unique_ptr<BaseSolver>(nullptr);
    }
}

#endif //CHALLENGE_2_SOLVER_UTILITIES_H
