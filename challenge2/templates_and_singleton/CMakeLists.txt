cmake_minimum_required(VERSION 3.20)
project(challenge2_update)

set(CMAKE_CXX_STANDARD 20)

add_executable(challenge2_update main.cpp BaseSolver.h TypeTraits.h Bisection.h SolverFactory.h Newton.h)
