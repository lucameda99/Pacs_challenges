CXX      ?= g++
CXXFLAGS ?= -std=c++20
CPPFLAGS ?= -O3 -Wall -I. -Wno-conversion-null -Wno-deprecated-declarations

EXEC     = main
LDFLAGS ?= 
LDLIBS  ?= 

# Flags for the muParser example.
CPPFLAG_MUPARSER ?= -I../../../../Examples/include
EXEC_MUPARSER     = main
LDFLAGS_MUPARSER ?= -L../../../../Examples/lib -Wl,-rpath=../../../../Examples/lib
LIB_MUPARSER     ?= -lmuparser

HEADERS = Bisection.h Secant.h RegulaFalsi.h extendedAssert.hpp SolverFactory.h TypeTraits.h BrentSearch.h BaseSolver.h QuasiNewton.h Newton.h

all: $(EXEC) $(EXEC_MUPARSER)	# controlla aggiornamenti su tutti gli eseguibili (main.... e main_getpot_muparser)

%.o: %.cpp $(HEADERS)
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $<

$(EXEC_MUPARSER).o: %.o: %.cpp $(HEADERS) muparser_fun.hpp
	$(CXX) -c $(CPPFLAGS) $(CPPFLAG_MUPARSER) $(CXXFLAGS) $<

$(EXEC): %: %.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $< $(LIBS) -o $@

$(EXEC_MUPARSER): %: %.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(LDFLAGS_MUPARSER) $< $(LIBS) $(LIB_MUPARSER) -o $@

clean:
	$(RM) *.o
	$(RM) $(EXEC) $(EXEC_MUPARSER)
	$(RM) *~
