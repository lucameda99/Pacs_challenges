cmake_minimum_required(VERSION 3.20)
project(challenge1)

set(CMAKE_CXX_STANDARD 20)

add_executable(challenge1 main.cpp
        ODEsolver.hpp
        ODEsolver.cpp
        newton.hpp
        basicZeroFun.hpp
        extendedAssert.hpp
        functionConcepts.hpp)
