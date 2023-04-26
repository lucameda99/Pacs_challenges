//
// Created by Ema on 13/04/2023.
//

#ifndef CHALLENGE2_UPDATE_SOLVERFACTORY_H
#define CHALLENGE2_UPDATE_SOLVERFACTORY_H

#include <unordered_map>
#include <functional>
#include <memory>

#include "TypeTraits.h"
#include "BaseSolver.h"

#include "Bisection.h"
#include "Newton.h"
#include <exception>
#include "RegulaFalsi.h"
#include "Secant.h"
// #include "BracketInterval.h"
#include "BrentSearch.h"
#include "QuasiNewton.h"

using ID = TypeTraits::ID;
using ScalarFunction = TypeTraits::ScalarFunction;
using Real = TypeTraits::Real;

class SolverFactory {
public:
    /*implement this class as a Singleton*/
    SolverFactory(SolverFactory const &) = delete;
    SolverFactory & operator = (SolverFactory const &) = delete;

    static SolverFactory& Instance(){
        static SolverFactory theSingleton;
        return theSingleton;
    }

    template <typename solver, typename... Args>
    void addSolver(const ID& name, Args&&... args){
        m_solvers[name] = [&]() { return std::make_unique<solver>(std::forward<Args>(args)...); };
        std::cout << "\n\t New solver " << name << " has been added." << std::endl;
        //.emplace(name, []() { return std::make_unique<solver>(); });
    }

    std::unique_ptr<BaseSolver> selectSolver(const ID& name) const {
        auto it = m_solvers.find(name);
        if (it == m_solvers.end()) {
            throw std::runtime_error ("This solver doesn't exist");
            //std::cout << "\n\t Solver " << name << " doesn't exist" << std::endl;
            return nullptr;
        }
        return it->second();
    }
private:

    SolverFactory()=default;

    std::unordered_map<ID, std::function<std::unique_ptr<BaseSolver>()>> m_solvers;
};


#endif //CHALLENGE2_UPDATE_SOLVERFACTORY_H
