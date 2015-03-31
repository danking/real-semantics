OBJECTS = example1.o example2.o

EXAMPLES = example1.out example2.out

REALLIBDIR = ../RealLib
	
all: $(OBJECTS) $(EXAMPLES)

noobjects: $(OBJECTS)

%.out: %.o $(REALLIBDIR)/Real.a
	$(CXX) $(CXXFLAGS) -o $@ $< $(REALLIBDIR)/Real.a -lm

%.o: %.cpp $(REALLIBDIR)/Real.h $(REALLIBDIR)/RealEstimate.h $(REALLIBDIR)/MachineEstimate.h
	$(CXX) $(CXXFLAGS) -c $< -I$(REALLIBDIR)
	
clean:
	rm -f *.o *.out
