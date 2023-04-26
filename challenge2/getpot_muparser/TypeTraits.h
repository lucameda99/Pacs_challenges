/*!
* Collects the Types of the project
*/
#ifndef CHALLENGE2_UPDATE_TYPETRAITS_H
#define CHALLENGE2_UPDATE_TYPETRAITS_H
#include "extendedAssert.hpp"

namespace TypeTraits {

    using ResultType = std::tuple<double, bool>;
    using ID = std::string;
    using Real = double;
    using ScalarFunction = std::function<double(double)>;
    using iterType = unsigned int;
}

#endif //CHALLENGE2_UPDATE_TYPETRAITS_H
