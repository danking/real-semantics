# Real Semantics

## Building the custom LLVM interpreter (`lli`)

### Prerequisites

 * A modern C++ toolchain (>=`g++-4.8` or a recent version of `clang`)
 * MPFR library (and also GMP, but it should install automatically if you get it through some sort of package manager)
 * List of dependencies described in the [LLVM Getting Started page](http://llvm.org/docs/GettingStarted.html#software). A few comments...
   * Install the `build-essential` if using Ubuntu Linux: that should install most of the required packages
   * If you're building on Mac, make sure to install all packages required by LLVM, including something called `m4` and a bunch of compression libraries
   * `g++-multilib`, if you are using `gcc` to build LLVM
   * `cmake`, which is used to configure the build system

### After you get all the tools...

1. Clone the [real-semantics repository](https://github.com/danking/real-semantics), and checkout the `llvm` submodule:

```bash
$ git clone git@github.com:danking/real-semantics.git
$ cd real-semantics
$ git submodule init && git submodule update
$ cd llvm-3.6.0
```

2. Note that at this step you are looking at an UNMODIFIED, ORIGINAL LLVM-3.6.0 copy! To get the custom LLVM, switch to master branch and apply the latest changes:

```bash
$ git checkout master
$ git pull
```

3. Now we can start building LLVM:

```bash
$ mkdir build
$ cd build
build/$ cmake .. -DCMAKE_INSTALL_PREFIX=$HOME/toolchains -DLLVM_ENABLE_EH=ON -DLLVM_ENABLE_RTTI=ON
build/$ make -j2 # or whatever number of processers you have
```

4. Keep your fingers crossed and hope that it will build without error... Actually it will probably fail at a final linking step because I haven't figured out the Makefile yet. If that happens, go to `build/tools/lli/CMakeFiles/lli.dir/link.txt` and add `-lmpfr -lgmp` to the end of that file, and run `make` (in the `build` directory!) again.

5. After it successfully builds, the executable we care about is located at `build/bin/lli`.

## Compiling C/C++ programs into LLVM byte code and run them

1. Make sure that you have `clang` or `clang++` installed because we didn't actually build `clang` when we built LLVM.

2. Generating byte code is easy:

```bash
# this will generate the actual "byte" code
$ clang++ -emit-llvm -c program.c -o program.bc
# this will generate a human readable LLVM IR program
$ clang++ -S -emit-llvm -c program.c -o program.ll
```

It works without the `-c` option as well, but it will link the entire stdlib so it won't be very human readable.

3. To run the byte code with `lli`, use the `.bc` file:
```bash
# make sure you are using the correct lli executable...
$ ./lli -force-interpreter program.bc
```