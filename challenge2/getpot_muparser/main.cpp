#include <iostream>
#include <cmath>

#include "SolverFactory.h"
#include <GetPot>
#include "muparser_fun.hpp"

/*!
* Example usage of the SolverFactory class. The additional function
* bracketInterval may be used to set up the initial interval.
*
* @function bracketInterval: finds a suitable initial interval [a,b]
*/

std::tuple<Real, Real, bool>
bracketInterval(TypeTraits::ScalarFunction const &f, Real x1, Real h = 0.01,
                iterType maxIter = 200);

int main() {

    // read functions from file
    GetPot datafile("data.txt");
    const std::string f_str = datafile("f", "0");
    const std::string df_str = datafile("df", "0");
    MuparserFun F(f_str), dF(df_str);

    std::cout << "\n\t f(x) = " << f_str << std::endl;
    std::cout << "\n\t df(x) = " << df_str << std::endl;

/*
    TypeTraits::ScalarFunction F = [] (double x){return 0.5 - exp(M_PI*x); };
    TypeTraits::ScalarFunction dF = [] (double x){return -M_PI*exp(M_PI*x); };
*/

    //exact result:
    Real root = 1/M_PI* log(0.5);
    std::cout << "\n\t Exact result = " << root << std::endl;

    // Instantiating SolverFactory
    auto & factory = SolverFactory::Instance();

    Real start = -1;

    std::tuple<Real, Real, bool> interval = bracketInterval(F,start);
    std::cout << "\n\t BracketInterval search has reached convergence: " << std::get<2>(interval) << std::endl;

    Real a = std::get<0>(interval);
    Real b = std::get<1>(interval);

    std::cout << "\n\t Interval: [" << a << ", " << b << "]" << std::endl;

    // adding solvers to factory
    factory.addSolver<Bisection>("bisection", F, a, b);
    factory.addSolver<Newton>("newton", F, dF, a, b);
    factory.addSolver<RegulaFalsi>("regulafalsi", F, a, b);
    factory.addSolver<Secant>("secant", F, a, b);
    factory.addSolver<BrentSearch>("brentsearch", F, a, b);
    factory.addSolver<QuasiNewton>("quasinewton", F, a, b);

    //___SOLVE___

    // solving with bisection method
    auto solver = factory.selectSolver("bisection");
    if (!solver) {return 0;}
    std::cout << "\n\t bisection: "<< std::get<0>(solver->solve()) << std::endl;
    //todo: print the output with the correct number of decimal digits

    // solving with newton method
    solver = factory.selectSolver("newton");
    if (!solver) {return 0;}
    ResultType result = solver->solve();
    std::cout << "\n\t newton: "<< std::get<0>(result) << ", converged: " << std::get<1>(result) << std::endl;

    // solving with regulafalsi method
    solver = factory.selectSolver("regulafalsi");
    if (!solver) {return 0;}
    std::cout << "\n\t regulafalsi: "<< std::get<0>(solver->solve()) << std::endl;

    // solving with secant method
    solver = factory.selectSolver("secant");
    if (!solver) {return 0;}
    result = solver->solve();
    std::cout << "\n\t secant: "<< std::get<0>(result) << ", converged: " << std::get<1>(result) << std::endl;

    // solving with Brentsearch method
    solver = factory.selectSolver("brentsearch");
    if (!solver) {return 0;}
    result = solver->solve();
    std::cout << "\n\t brentsearch: "<< std::get<0>(result) << ", converged: " << std::get<1>(result) << std::endl;

    // solving with Quasi Newton method
    solver = factory.selectSolver("quasinewton");
    if (!solver) {return 0;}
    result = solver->solve();
    std::cout << "\n\t quasinewton: "<< std::get<0>(result) << ", converged: " << std::get<1>(result) << std::endl;

    // selecting a non-existent solver
    solver = factory.selectSolver("bisection_method");
    if (!solver) {return 0;}
    solver->solve(); // solving with bisection_method

    return 0;
}

std::tuple<Real, Real, bool>
bracketInterval(ScalarFunction const &f, Real x1, Real h,
                iterType maxIter)
{
  constexpr Real expandFactor = 1.5;
  h = std::abs(h);
  // auto          hinit = h;
  auto         direction = 1.0;
  auto         x2 = x1 + h;
  auto         y1 = f(x1);
  auto         y2 = f(x2);
  iterType iter = 0u;
  // get initial decrement direction
  while((y1 * y2 > 0) && (iter < maxIter))
    {
      ++iter;
      if(std::abs(y2) > std::abs(y1))
        {
          std::swap(y1, y2);
          std::swap(x1, x2);
          // change direction
        }
      direction = (x2 > x1) ? 1.0 : -1.0;
      x1 = x2;
      y1 = y2;
      x2 += direction * h;
      y2 = f(x2);
      h *= expandFactor;
    }
  return std::make_tuple(x1, x2, iter < maxIter);
}