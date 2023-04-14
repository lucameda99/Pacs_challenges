#ifndef SOLVERTRAITS_HPP
#define SOLVERTRAITS_HPP

#include<functional>

class SolverTraits {
public:
    using ResultType = double;
    using Function = std::function<ResultType(ResultType)>;
};

#endif //SOLVERTRAITS_HPP
