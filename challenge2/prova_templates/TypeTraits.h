//
// Created by Ema on 13/04/2023.
//

#ifndef CHALLENGE2_UPDATE_TEMPLATE_CLASSES_TYPETRAITS_H
#define CHALLENGE2_UPDATE_TEMPLATE_CLASSES_TYPETRAITS_H

namespace TypeTraits {

    using ResultType = double;
    using ID = std::string;
    //using Builder =  std::function<std::shared_ptr<BaseSolver>()>
    using Real = double;
    using ScalarFunction = std::function<Real(Real)>;
}

#endif //CHALLENGE2_UPDATE_TEMPLATE_CLASSES_TYPETRAITS_H
