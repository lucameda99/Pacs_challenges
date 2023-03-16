CC=$(CXX)
SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:.cpp=.o)
HEADERS=$(wildcard *.hpp)

exe_sources=$(filter main%.cpp,$(SRCS))
EXEC=$(exe_sources:.cpp=)

.PHONY=all resclean
all: $(EXEC)

exe:
	$(MAKE)
	./main
	
plot:
	$(MAKE) exe
	gnuplot -p -e "plot 'result.dat' u 1:2 w lp lw 2 title 'uh'"

clean: 
	$(RM) $(EXEC) $(OBJS) 
	
resclean:
	$(MAKE) clean
	$(RM) result.dat

$(EXEC): $(OBJS)
$(OBJS): $(SRCS) $(HEADERS)
