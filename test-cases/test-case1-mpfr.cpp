#include <iostream>
#include <iomanip>
#include <vector>
#include "real.hpp"

#define PREC 4096

int main(int argc, char ** argv) {
  std::vector<mpfr::real<PREC> > xs;
  xs.push_back(mpfr::real<4096>(1000000));
  xs.push_back(mpfr::real<4096>(0.01));
  xs.push_back(mpfr::real<4096>(0.01));
  xs.push_back(mpfr::real<4096>(0.01));
  xs.push_back(mpfr::real<4096>(0.01));

  mpfr::real<PREC> sum(0);

  for (int i=0; i < 5; ++i) {
    std::cout << std::setprecision(10) << sum << " + " << xs[i] << std::endl;
    sum += xs[i];
  }

  std::cout << sum << std::endl;

  return 0;
}
