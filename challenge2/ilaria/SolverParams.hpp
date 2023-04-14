#ifndef SOLVERPARAMS_HPP
#define SOLVERPARAMS_HPP

#include<string>
#include"SolverTraits.hpp"

class SolverParams {
public:
    using ResultType = SolverTraits::ResultType;
    
    // constructor
    explicit SolverParams(const std::string &filename);

    ResultType a;
    ResultType b;

    ResultType tol;
    ResultType tola;
    unsigned int maxIt;

    std::string name;

};

#endif //SOLVERPARAMS_HPP
