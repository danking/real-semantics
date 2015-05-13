#include <stdio.h>


int main(int argc, char ** argv) {
  double xs [15] = {100000000000, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01};

  double sum = 0;

  for (int i=0; i < 5; ++i) {
    sum += xs[i];
  }

  printf("%f\n", sum);

  return 0;
}
