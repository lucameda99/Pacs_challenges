cmake_minimum_required(VERSION 3.20)
project(chellenge1_muparser)

set(CMAKE_CXX_STANDARD 20)

add_executable(challenge1_muparser
        main_getpot_muparser.cpp
        muparser_fun.hpp
        ODEsolver.hpp
        ODEsolver.cpp
        newton.hpp
        basicZeroFun.hpp
        extendedAssert.hpp
        functionConcepts.hpp)
