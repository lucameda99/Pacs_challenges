#include <iostream>
#include <cmath>

#include "SolverFactory.h"
#include "Bisection.h"
#include "TypeTraits.h"

int main() {
    const TypeTraits::ScalarFunction F = [] (double x){return 0.5 - exp(M_PI*x); };

    SolverFactory factory;
    factory.addSolver<Bisection<TypeTraits::ScalarFunction>>("Bisection_method");
    return 0;
}

/*
 * In template: non-object type 'std::unordered_map<std::basic_string<char>,
 * std::shared_ptr<BaseSolver<std::function<double (double)>>> ()>::mapped_type'
 * (aka 'std::shared_ptr<BaseSolver<std::function<double (double)>>> ()') is not assignable
 */