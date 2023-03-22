cmake_minimum_required(VERSION 3.20)
project(chellenge1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-std=c++20")

add_executable(chellenge1
        main.cpp
        main_getpot_muparser.cpp
        muparser_fun.hpp
        ODEsolver.h
        ODEsolver.cpp
        newton.hpp
        basicZeroFun.hpp
        extendedAssert.hpp
        functionConcepts.hpp)
