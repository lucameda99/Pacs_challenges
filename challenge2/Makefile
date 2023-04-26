CXX = g++
CXXFLAGS = -std=c++20 -O3 -Wall -I. # -I./include

EXEC = Solvers

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
# HEADERS = newton.hpp ODEsolver.hpp
HEADERS = Bisection.h Secant.h Regulafalsi.h extendedAssert.hpp SolverFactory.h TypeTraits.h BrentSearch.h BaseSolver.h QuasiNewton.h Newton.h

.PHONY: all clean #"all" and "clean" are not filenames

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	$(RM) $(OBJS) $(EXEC)
