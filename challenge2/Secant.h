//
// Created by BARBARA on 12/04/2023.
//

#ifndef CHALLENGE_2_SECANT_H
#define CHALLENGE_2_SECANT_H

#include "Traits.h"
#include "BaseSolver.h"

namespace zerosolvers {

    class Secant final : public BaseSolver {


    public:
        Traits::ScalarFunction m_f;
        Traits::scalar m_a;
        Traits::scalar m_b;
        Traits::scalar m_tol;
        Traits::scalar m_tola;
        unsigned int m_maxIt;


        Secant(Traits::ScalarFunction &f,Traits::scalar a,Traits::scalar b,Traits::scalar tol);

        Traits::ReturnType solve() override;



    };

}


#endif //CHALLENGE_2_SECANT_H
