# Real Semantics

## Building the custom LLVM interpreter (`lli`)

### Prerequisites

 * A modern C++ toolchain (>=`g++-4.8` or a recent version of `clang`)
 * MPFR library (and also GMP, but it should install automatically if you get it through some sort of package manager)
 * List of dependencies described in the [LLVM Getting Started page](http://llvm.org/docs/GettingStarted.html#software). A few comments...
   * Install the `build-essential` package if using Ubuntu Linux: that should install most of the required packages
   * If you're building on Mac, make sure to install all packages required by LLVM, including something called `m4` and a bunch of compression libraries
   * Be sure to install `libffi`, or library calls such as `printf()` won't work. On Ubuntu Linux systems it should come with the box. If not, the `apt-get` package name is `libffi-dev`. Sorry but I don't know its OSX equivalence...
   * Install `g++-multilib`, if you are using `gcc` to build LLVM
   * Install `cmake`, which is used to configure the build system

### After you get all the tools...

1. Clone this repository and checkout the `llvm` submodule:

   ```bash
   $ git clone git@github.com:danking/real-semantics.git
   $ cd real-semantics
   $ git submodule init && git submodule update
   $ cd llvm-3.6.0
   ```

2. If you would like to get the latest LLVM code (which could be broken), switch to master branch and do a pull. You can skip this step if you just want to try it out.

   ```bash
   $ git checkout master
   $ git pull
   ```

3. Now we can start building LLVM:

   ```bash
   $ mkdir build
   $ cd build
   build$ cmake .. -DLLVM_ENABLE_EH=ON -DLLVM_ENABLE_RTTI=ON -DLLVM_ENABLE_FFI=ON
   build$ make -j2 # or whatever number of processors you have
   ```

   During the third (`cmake`) step, you can pass `'-DCMAKE_BUILD_TYPE=DEBUG -DLLVM_ENABLE_ASSERTIONS=ON'` as additional arguments if you wish to do a debug build.

4. Keep your fingers crossed and hope that it will build without error... Actually it will probably fail at a final linking step because I haven't figured out the Makefile yet. If that happens, go to `build/tools/lli/CMakeFiles/lli.dir/link.txt` and add `-lmpfr -lgmp` to the end of that file, and run `make` (in the `build` directory!) again.

5. After it successfully builds, the executable we care about is located at `build/bin/lli`.

## Compiling C/C++ programs into LLVM byte code and run them

1. Make sure that you have `clang` or `clang++` installed because we didn't actually build `clang` when we built LLVM.

2. Generating byte code is easy:

   ```bash
   # this will generate the actual "byte" code
   $ clang -emit-llvm -c program.c -o program.bc
   # this will generate a human readable LLVM IR program
   $ clang -S -emit-llvm -c program.c -o program.ll
   ```

   Notes:
   * Be sure to supply the `-c` flag; `-emit-llvm` doesn't work without it.
   * Supply the `-g` flag if you want extra debugging information (e.g. line number)
   * Supply the `-fno-use-cxa-atexit` flag if you encounter a `__dso_handle`-related error in the next step.

3. To run the byte code with `lli`, use the `.bc` file. DO NOT forget to invoke `lli` with the `-force-interpreter` flag:
   ```bash
   # make sure you are using the correct lli executable...
   $ ./lli -force-interpreter program.bc
   ```
