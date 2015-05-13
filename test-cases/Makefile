BITCODEFILES=test-case1-float.bc test-case2-pow.bc test-case3-malloc.bc test-case4-memcpy.bc excel.bc inverse_matrix.bc numeric_int.bc polygon.bc prob.bc
READABLEFILES=test-case1-float.ll test-case2-pow.ll test-case3-malloc.ll test-case4-memcpy.ll excel.ll inverse_matrix.ll numeric_int.ll polygon.ll prob.ll

default: $(BITCODEFILES)

readable: $(READABLEFILES)

clean:
	rm -rf $(BITCODEFILES)

%.bc: %.cpp
	clang++ -emit-llvm -c $*.cpp -o $@

%.ll: %.cpp
	clang++ -S -emit-llvm -c $*.cpp -o $@

%.bc: %.c
	clang -emit-llvm -c $*.c -o $@

%.ll: %.c
	clang -S -emit-llvm -c $*.c -o $@
