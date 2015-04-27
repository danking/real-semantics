BITCODEFILES=example.bc

default: $(BITCODEFILES)

clean:
	rm -rf $(BITCODEFILES)

%.bc: %.c
	clang -emit-llvm -c $*.c -o $@

