#ifndef CHALLENGE2_UPDATE_BASESOLVER_H
#define CHALLENGE2_UPDATE_BASESOLVER_H

#include "TypeTraits.h"

/*!
* Base class from which all the solvers will be derived.
*
* @tparam m_f Function that has to be solved
* @param f The function
* @param a First end of initial interval
*/

using ResultType = TypeTraits::ResultType;
using ScalarFunction = TypeTraits::ScalarFunction;

class BaseSolver {
    protected:
        ScalarFunction m_f;

    public:
        BaseSolver(const ScalarFunction &f);
        virtual ~BaseSolver() {}
        virtual ResultType solve() const = 0;
};

BaseSolver::BaseSolver(const ScalarFunction &f) : m_f(f) {}
#endif //CHALLENGE2_UPDATE_BASESOLVER_H