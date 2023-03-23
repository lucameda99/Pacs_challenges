CXX      ?= g++
CXXFLAGS ?= -std=c++20
CPPFLAGS ?= -O3 -Wall -I. -Wno-conversion-null -Wno-deprecated-declarations

EXEC     = main
LDFLAGS ?= 
LDLIBS  ?= 

# Flags for the muParser example.
CPPFLAG_MUPARSER ?= -I./ -I/include
EXEC_MUPARSER     = main_getpot_muparser
LDFLAGS_MUPARSER ?= -L/lib -Wl,-rpath=/lib
LIB_MUPARSER     ?= -lmuparser

HEADERS = ODEsolver.hpp basicZeroFun.hpp Derivatives.hpp extendedAssert.hpp functionConcepts.hpp

all: $(EXEC) $(EXEC_MUPARSER)

%.o: %.cpp $(HEADERS)
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $<

$(EXEC_MUPARSER).o: %.o: %.cpp $(HEADERS) muparser_fun.hpp # here we're adding muparser_fun.hpp
	$(CXX) -c $(CPPFLAGS) $(CPPFLAG_MUPARSER) $(CXXFLAGS) $<

$(EXEC): %: %.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $< $(LIBS) -o $@

$(EXEC_MUPARSER): %: %.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(LDFLAGS_MUPARSER) $< $(LIBS) $(LIB_MUPARSER) -o $@

clean:
	$(RM) $(EXEC) $(EXEC_MUPARSER)
	$(RM) *~
	$(RM) output.txt
	$(RM) output.png
	$(RM) convergence_rate.txt
	$(RM) convergence_rate.png

