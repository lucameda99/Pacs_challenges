#include <iostream>
#include <cmath>
#include <fstream>
#include <functional>
#include <vector>

#include "basicZeroFun.hpp"
#include "BackwardEuler.hpp"

using std::vector;

int main()
{
    double T = 1.; 	// final time
    double y0 = 0; 	// initial condition
    unsigned N = 100;	// number of steps
    const std::function<double(double, double)> fun = [](double t, double x ) { 
    	return -t*(exp(-x)); 
    	};	// function
    
    // we use BackwardEuler to compute the solution
    auto sol = BackwardEuler(y0, T, N, fun);

    vector<double> tn = std::get<0>(sol);
    vector<double> un = std::get<1>(sol);
    
    // print the solution
    for (size_t i = 0; i < N+1; i++)
        std::cout << tn[i] << "   " << un[i] << std::endl;

    // create the file result.dat and store the solution in it
    std::ofstream f("result.dat");

    f << "#node coordinate\tcomputed solution" << std::endl;
    for(size_t m = 0; m <= N; m++)
    {
        f.setf(std::ios::left, std::ios::adjustfield);
        f.width(16);
        f << tn[m] << "\t\t" << un[m] << "\n";
    }
    
    return 0;
}


