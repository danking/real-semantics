#include <iostream>
#include <iomanip>
#include <vector>
#include "real.h"

int main(int argc, char ** argv) {
 	RealLib::InitializeRealLib();


  std::vector<RealLib::Real> xs;

  xs.push_back(RealLib::Real("1000000"));
  xs.push_back(RealLib::Real("0.01"));
  xs.push_back(RealLib::Real("0.01"));
  xs.push_back(RealLib::Real("0.01"));
  xs.push_back(RealLib::Real("0.01"));

  /* do not set to zero. RealLib::Real("0") is infinity. For some reason. */
  RealLib::Real sum("1");

  std::cout << sum << std::endl;

  for (int i=0; i < 5; ++i) {
    std::cout << std::setprecision(15) << sum
              << " + " << xs[i] << std::endl;
    sum += xs[i];
  }

  std::cout << sum << std::endl;

  unsigned pr = RealLib::FinalizeRealLib();

  return 0;
}
