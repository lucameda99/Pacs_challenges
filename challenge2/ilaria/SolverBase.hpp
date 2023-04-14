#ifndef SOLVERBASE_HPP
#define SOLVERBASE_HPP

#include"SolverTraits.hpp"
#include<functional>

class SolverBase {
public:
    using Function = SolverTraits::Function;
    using ResultType = SolverTraits::ResultType;
    
    // constructor
    SolverBase(const Function &fun); 
    
    // virtual method implemented in the derived classes
    virtual ResultType solve() = 0; 
    
    // destructor
    virtual ~SolverBase() = default;

protected:
    const Function &fun;
};

#endif //SOLVERBASE_HPP
