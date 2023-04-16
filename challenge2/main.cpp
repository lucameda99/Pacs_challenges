//
// Created by BARBARA on 12/04/2023.
//

#include "BaseSolver.h"
#include "Bisection.h"
#include "Secant.h"
#include "Regulafalsi.h"
#include "Solver_Utilities.h"
#include "Traits.h"
#include <functional>
#include <math.h>
#include <iostream>

using T = zerosolvers::Traits;

T::scalar f (T::scalar x) {
    constexpr double pi = 3.1415;
    double res = 0.5 - std::exp(pi * x);
    return res;
}

int main(){

    T::ScalarFunction fun = &f;
    T::scalar a=-2;
    T::scalar b=-0;
    T::scalar tol=1e-5;

auto sol = zerosolvers::createSolver<>("Bisection",fun,a,b,tol);
auto result = sol->solve();
std::cout << std::get<0>(result) << std::endl;
}