#ifndef PACS1_BACKWARDEULER_HPP
#define PACS1_BACKWARDEULER_HPP

#endif //PACS1_BACKWARDEULER_HPP

#include <iostream>
#include <vector>
#include <tuple>
#include <functional>
#include <algorithm>
#include <cmath>

#include "basicZeroFun.hpp"

// definition of the numerical method
std::tuple<std::vector<double>, std::vector<double>> BackwardEuler(double y0, double T, unsigned N, std::function<double(double, double)> f);






















