default: test-case1-mpfr test-case1-float

run:
	echo 'MPFR:\n' && ./test-case1-mpfr && echo 'FLOAT:\n' && ./test-case1-float

clean:
	rm -rf test-case1-mpfr test-case1-float

%: %.cpp
	clang++ $@.cpp -lmpfr -lgmp -o $@
