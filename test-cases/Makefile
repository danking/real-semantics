default: test-case1-mpfr test-case1-float test-case1-reallib

run:
	echo 'MPFR:\n' && ./test-case1-mpfr && echo 'FLOAT:\n' && ./test-case1-float && echo 'REALLIB:' && ./test-case1-reallib

clean:
	rm -rf test-case1-mpfr test-case1-float

test-case1-reallib : test-case1-reallib.cpp
	clang++ test-case1-reallib.cpp -I../RealLib -L../RealLib \
    -o test-case1-reallib ../RealLib/Real.a -lm

%: %.cpp
	clang++ $@.cpp -lmpfr -lgmp -o $@
