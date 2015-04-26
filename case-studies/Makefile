BITCODEFILES=raytracer.bc
READABLEFILES=raytracer.ll

default: $(BITCODEFILES)

readable: $(READABLEFILES)

clean:
	rm -rf $(BITCODEFILES)

%.bc: %.cpp
	clang++ -emit-llvm -c $*.cpp -o $@

%.ll: %.cpp
	clang++ -S -emit-llvm -c $*.cpp -o $@
