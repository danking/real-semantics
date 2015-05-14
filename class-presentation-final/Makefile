BITCODEFILES=test.bc challenge.bc
READABLEFILES=test.ll challenge.ll

LLVM_LINK=llvm-link
REAL_LLI=../llvm-3.6.0/build/bin/lli

default: $(BITCODEFILES)

readable: $(READABLEFILES)

clean:
	rm -rf $(BITCODEFILES) $(READABLEFILES)

%.bc: %.cpp
	clang++ -emit-llvm $*.cpp -o $@

%.bc: %.c
	clang -emit-llvm -c $*.c -o $@

%.ll: %.cpp
	clang++ -S -emit-llvm -c $*.cpp -o $@

%.ll: %.c
	clang -S -emit-llvm -c $*.c -o $@

test: $(BITCODEFILES)
	$(LLVM_LINK) 
	$(REAL_LLI) test.bc
