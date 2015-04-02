#include <iostream>
#include <iomanip>
#include <vector>

#define PREC 4096

int main(int argc, char ** argv) {
  std::vector<float> xs;
  xs.push_back(1000000);
  xs.push_back(0.01);
  xs.push_back(0.01);
  xs.push_back(0.01);
  xs.push_back(0.01);

  float sum = 0;

  for (int i=0; i < 5; ++i) {
    std::cout << std::setprecision(10) << sum << " + " << xs[i] << std::endl;
    sum += xs[i];
  }

  std::cout << sum << std::endl;

  return 0;
}
