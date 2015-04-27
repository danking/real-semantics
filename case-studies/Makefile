BITCODEFILES=raytracer.bc misc-tests.bc
READABLEFILES=raytracer.ll misc-tests.ll

FLAGS=-fno-use-cxa-atexit

default: $(BITCODEFILES)

readable: $(READABLEFILES)

clean:
	rm -rf $(BITCODEFILES)

%.bc: %.cpp
	clang++ -emit-llvm $(FLAGS) -c $*.cpp -o $@

%.bc: %.c
	clang -emit-llvm $(FLAGS) -c $*.c -o $@

%.ll: %.cpp
	clang++ -S -emit-llvm $(FLAGS) -c $*.cpp -o $@
