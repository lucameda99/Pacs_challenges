#include <iostream>
#include <cmath>
#include <vector>
#include <functional>
#include <fstream>
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
int main(int argc, char **argv){

    std::cout << "start debug"<< std::endl;
    // ODEsolver solver(f,fprime,0,1,100);
    ODEsolver solver(f,0,1,20);

    solver.solveCN();

    // get the solution with the getters, ostream...
    vector<double> t = solver.getT();
    vector<double> U = solver.getU();

    if(t.size()!=U.size())
        std::cerr<<"t and U do NOT have the same size"<<std::endl;

    // postprocessing
    // print
    for(const auto &i : U){
        std::cout << i << std::endl;
    }
    // save in a txt file
    std::ofstream outFile("output.txt");

    if(not(outFile.is_open()))
        std::cerr<<"\n\t file not opened"<<std::endl;
    if((outFile.fail()))
        std::cerr<<"\n\t file failed"<<std::endl;

    for(size_t i = 0; i<t.size(); i++)
        outFile << t[i] << "\t" << U[i] << "\n";
    outFile.close();

    return 0;
}