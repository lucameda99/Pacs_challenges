#include <iostream>
#include <vector>
#include <tuple>
#include <functional>
#include <algorithm>
#include <cmath>

#include "basicZeroFun.hpp"
#include "BackwardEuler.hpp"

// This function implements Backward Euler method to find the solution of a differential equation dy(t)/dt = f(t, y(t)) 

// takes as input the function f, initial condition y0, final time T, number of steps N
// returns the approximation of the solution un and the temporal discretization tn

std::tuple<std::vector<double>, std::vector<double>> BackwardEuler(double y0, double T, unsigned N, std::function<double(double, double)> f){

    // vectors un, tn initialized with the initial condition and the time 0
    std::vector<double> un {y0};
    std::vector<double> tn {0.};

    // time step h
    double h = T/N;

    for (size_t n = 0; n < N; n++) {
        
        // tn = n*h (n from 1 to N-1)
        tn.push_back((n+1) * h);
	
	// we define the function F
	// at each time index n, the zero of this F is equal to the solution  
        std::function<double(double)> F = [&h, &tn, &un, &f, &n](double x) {
        	return x - h * f(tn[n+1], x) - un[n];
        	};

        // We use the secant method  
        // It returns the approximation of the zero of F and a status (false if not converging)
        auto sol = apsc::secant(F, 0, T, 1e-4, 1.e-10, 150);

        // If the solution converges, it will be added in un, otherwise print an error
        if (std::get<1>(sol))
            un.push_back(std::get<0>(sol));
        else 
            std::cerr << "The secant method doesn't converge" << std::endl; 
    }
    
    // return tuple with tn, un 
    return std::make_tuple(tn, un);
}




