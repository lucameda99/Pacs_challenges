#include <iostream>
#include <cmath>
#include <vector>
#include <functional>
#include <fstream>
#include <numbers>

#include "ODEsolver.hpp"

#include <GetPot>
#include "muparser_fun.hpp"
#include "muparser_sol.hpp"

using std::vector;
using std::function;

void test_convergence(const std::vector<double>&, const double&, const double&,
        const double&,std::function<double(double, double)> f,
                      std::function<double(double, double)> Uex);
double L2_norm(const std::vector<double>&, const std::vector<double>&);

int main(int argc, char **argv){

    GetPot datafile("data.txt");
    const std::string f_str = datafile("f", "-t * exp(-y)");
    const std::string uex_str  = datafile("uex", "log(1-t*t*0.5)");

    MuparserFun f(f_str), uex(uex_str);

    const double y0 = datafile("y0", 0);
    const double T = datafile("Tf", 1);
    const double n = datafile("N", 10);
    const double theta = datafile("theta", 0.5);
    const bool convergence = datafile("do_convergence_test", 0);

    const std::vector<double> N = datafile("convergence_steps", {10, 20, 30, 40, 50});

    // start solving one problem
    ODEsolver solver(f,y0,T,n);
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

    // if users wants, perform convergence test
    if(convergence)
        test_convergence(N, y0, T, theta, f, uex);

    return 0;
}

void test_convergence(const std::vector<unsigned int>& N, const double& y0, const double& T,
                      const double& theta, std::function<double(double, double)> f,
                      std::function<double(double, double)> Uex){

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