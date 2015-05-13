#include <stdio.h>
#include <math.h>

// calculate int_{0, M_PI}(sin(x))dx

int main() {
  float lower = 0.0;
  float upper = M_PI;
  float step = 0.0001;

  float result = 0.0;
  float x;

  for (x = lower; x < upper; x += step) {
    result += sin(x) * step;
  }

  printf("%f\n", result);

  return 0;
}