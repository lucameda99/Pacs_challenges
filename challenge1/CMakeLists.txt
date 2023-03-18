cmake_minimum_required(VERSION 3.20)
project(chellenge1)

set(CMAKE_CXX_STANDARD 20)

add_executable(chellenge1
        main.cpp
        ODEsolver.h
        ODEsolver.cpp
        newton.hpp
        basicZeroFun.hpp
        extendedAssert.hpp
        functionConcepts.hpp)
