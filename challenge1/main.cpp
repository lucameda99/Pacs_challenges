#include <iostream>
#include <cmath>
#include <vector>
#include <functional>
#include <fstream>
#include <numbers>

#include "ODEsolver.hpp"

using std::vector;
using std::function;

double f(const double t, const double y) {
    return -t * exp(-y);
}
/*
double fprime(const double t, const double y){
    return -exp(-y)+t*t*exp(-2*y);
}
 */
double Uex(const double t){
    if(t<-std::numbers::sqrt2 || t>std::numbers::sqrt2) {
        std::cout << "\n\t computing exact solution out of domain" << std::endl;
        return 0;
    }
    return log(1-t*t*0.5);
}

void test_convergence(const std::vector<unsigned int>& N, const double& y0, const double& T, const double& theta);
double L2_norm(const std::vector<double>&, const std::vector<double>&);

int main(int argc, char **argv){

    // std::cout << "start debug"<< std::endl;
    // ODEsolver solver(f,fprime,0,1,100);

    // ΞΞΞΞΞΞΞΞΞΞΞΞΞΞΞ SET PARAMETERS ! ΞΞΞΞΞΞΞΞΞΞΞΞΞΞΞ
    const double y0 = 0, T = 1, theta = 0.5;
    const unsigned int n = 10;
    std::vector<unsigned int> N = {10, 20, 40, 80, 160};
    // ΞΞΞΞΞΞΞΞΞΞΞΞΞΞΞΞΞΞΞΞΞΞΞΞΞΞΞΞΞΞΞΞΞΞΞΞΞΞΞΞΞΞΞΞΞΞΞΞ

    ODEsolver solver(f,y0,T,n,theta);

    solver.solveCN();

    // get the solution with the getters, ostream...
    vector<double> t = solver.getT();
    vector<double> U = solver.getU();

    if(t.size()!=U.size())
        std::cerr<<"t and U do NOT have the same size"<<std::endl;

    // postprocessing
    // print
    for(const auto &i : U)
        std::cout << i << std::endl;

    // save in a txt file
    std::ofstream outFile("output.txt");

    if(not(outFile.is_open()))
        std::cerr<<"\n\t file not opened"<<std::endl;
    if((outFile.fail()))
        std::cerr<<"\n\t file failed"<<std::endl;

    for(size_t i = 0; i<t.size(); i++)
        outFile << t[i] << "\t" << U[i] << "\n";
    outFile.close();

    test_convergence(N, y0, T, theta);

    return 0;
}

// test convergence facciamolo diventare un altro eseguibile
void test_convergence(const std::vector<unsigned int>& N, const double& y0, const double& T, const double& theta){

    // open output file
    std::ofstream outFile("convergence_rate.txt");
    if(not(outFile.is_open()))
        std::cerr<<"\n\t file not opened"<<std::endl;
    if((outFile.fail()))
        std::cerr<<"\n\t file failed"<<std::endl;

    for(auto &j : N){
        outFile << j << "\t";

        ODEsolver solver(f,y0,T,j,theta);
        solver.solveCN();

        // get the solution with the getters, ostream...
        vector<double> t = solver.getT();
        vector<double> U = solver.getU();

        if(t.size()!=U.size())
            std::cerr<<"t and U do NOT have the same size"<<std::endl;

        /*
         * non mi interessa salvare ogni soluzione, mi serve solamente la norma
         * tra U e la soluzione esatta calcolata in t
         * */

        // compute exact solution Uex in the points of t
        std::vector<double> U_ex;
        U_ex.reserve(t.size()); //allocate space for efficiency, don't fill
        for(auto &i : t)
            U_ex.emplace_back(Uex(i));

        // compute the L2 norm between the vector U and Uex
        double norm = L2_norm(U_ex, U);

        outFile << norm << "\n";
    }

    outFile.close();

}

double L2_norm(const std::vector<double>& a, const std::vector<double>& b) {
    double norm = 0.0;
    for (size_t i = 0; i < a.size(); i++)
        norm += (a[i] - b[i])*(a[i] - b[i]);
    return sqrt(norm);
}