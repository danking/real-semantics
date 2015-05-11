BITCODEFILES=main.bc
READABLEFILES=main.ll

FLAGS=-fno-use-cxa-atexit

default: $(BITCODEFILES)

readable: $(READABLEFILES)

clean:
	rm -rf $(BITCODEFILES)

%.bc: %.c
	clang -emit-llvm $(FLAGS) -c $*.c -o $@

%.ll: %.c
	clang -S -emit-llvm $(FLAGS) -c $*.c -o $@
