//
// Created by Ema on 13/04/2023.
//

#ifndef CHALLENGE2_UPDATE_TEMPLATE_CLASSES_SOLVERFACTORY_H
#define CHALLENGE2_UPDATE_TEMPLATE_CLASSES_SOLVERFACTORY_H


#include <unordered_map>
#include <functional>
#include <memory>

#include "TypeTraits.h"
#include "BaseSolver.h"

using ID = TypeTraits::ID;
using ScalarFunction = TypeTraits::ScalarFunction;

class SolverFactory {
public:
    /*
    template <typename T, typename... Args>
    void registerType(const ID& name, Args&&... args) {
        m_solvers[name] = [args...]() { return std::make_shared<T>(args...); };
    }
    */
    template <typename T>
    void addSolver(const ID& name) {
        m_solvers[name] = []() { return std::make_shared<T>(); };
        // m_solvers[name] = std::make_shared<T>();
    }
private:
    std::unordered_map<ID, std::function<std::shared_ptr<BaseSolver<ScalarFunction>>()>> m_solvers;
};

#endif //CHALLENGE2_UPDATE_TEMPLATE_CLASSES_SOLVERFACTORY_H
