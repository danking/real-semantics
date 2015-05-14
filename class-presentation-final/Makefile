BITCODEFILES=test.bc challenge.bc
READABLEFILES=test.ll challenge.ll

LLVM_LINK=./llvm-link
REAL_LLI=../llvm-3.6.0/build/bin/lli

default: $(BITCODEFILES)
	$(LLVM_LINK) $(BITCODEFILES) -o a.bc

readable: $(READABLEFILES)
	$(LLVM_LINK) -S $(BITCODEFILES) -o a.ll

clean:
	rm -rf $(BITCODEFILES) $(READABLEFILES) a.bc a.ll

%.bc: %.cpp
	clang++ -emit-llvm $*.cpp -o $@

%.bc: %.c
	clang -emit-llvm -c $*.c -o $@

%.ll: %.cpp
	clang++ -S -emit-llvm -c $*.cpp -o $@

%.ll: %.c
	clang -S -emit-llvm -c $*.c -o $@

test: $(BITCODEFILES) default
	$(REAL_LLI) -force-interpreter a.bc
