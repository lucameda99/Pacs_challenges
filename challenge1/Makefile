# first version of my MAKEFILE that doesn't bind any external library
CXX = g++
CXXFLAGS = -std=c++20 -O3 -Wall -I.

EXEC = CN_solver

SRCS = main.cpp ODEsolver.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = newton.hpp ODEsolver.hpp

.PHONY: all clean #"all" and "clean" are not filenames

all: $(EXEC) #target is "CN_solver", it checks for updates on CN_solver before rebuilding it?

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# extended lines become:
# g++ -std=c++20 -O3 -Wall -I.   -c -o main.o main.cpp
# g++ -std=c++20 -O3 -Wall -I.   -c -o ODEsolver.o ODEsolver.cpp
# g++ -std=c++20 -O3 -Wall -I. main.o ODEsolver.o -o CN_solver

clean:
	$(RM) $(OBJS) $(EXEC)
	$(RM) $(OBJS) output.txt

