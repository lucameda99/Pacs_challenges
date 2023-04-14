#ifndef SOLVERFACTORY_HPP
#define SOLVERFACTORY_HPP

#include "SolverBase.hpp"
#include "SolverTraits.hpp"
#include <string>
#include <memory>

class SolverFactory {
public:
    using Function = SolverTraits::Function;
    using ResultType = SolverTraits::ResultType;
    
    // call operator
    std::unique_ptr<SolverBase> operator()(const std::string &filename, const Function &fun);
   
private:
    std::string SolverName;
    std::string filename;
};


#endif //SOLVERFACTORY_HPP
