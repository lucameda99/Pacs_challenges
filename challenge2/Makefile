CXX      ?= g++
CXXFLAGS ?= -std=c++20
CPPFLAGS ?= -O3 -Wall -I. -Wno-conversion-null -Wno-deprecated-declarations

EXEC     = main
LDFLAGS ?= 
LDLIBS  ?= 

PACS_ROOT = /home/pacs-examples/

# Flags for the muParser library.
CPPFLAG_MUPARSER ?= -I$(PACS_ROOT)Examples/include
LDFLAGS_MUPARSER ?= -L$(PACS_ROOT)Examples/lib -Wl,-rpath=$(PACS_ROOT)Examples/lib
LIB_MUPARSER     ?= -lmuparser

HEADERS = Bisection.h Secant.h RegulaFalsi.h extendedAssert.hpp SolverFactory.h TypeTraits.h BrentSearch.h BaseSolver.h QuasiNewton.h Newton.h

all: $(EXEC)

%.o: %.cpp $(HEADERS)
	$(CXX) -c $(CPPFLAGS) $(CPPFLAG_MUPARSER) $(CXXFLAGS) $<

$(EXEC): %: %.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(LDFLAGS_MUPARSER) $< $(LIBS) $(LIB_MUPARSER) -o $@

clean:
	$(RM) *.o
	$(RM) $(EXEC)
	$(RM) *~
