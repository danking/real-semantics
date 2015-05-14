#include <stdio.h>
#include "challenge.h"

#define TEST_CASE_COUNT 9

double test_cases [TEST_CASE_COUNT * 3] =
  { 1, 10, 1,
    10, 100, 10,
    1e10, 1e11, 1e10,
    1e-10, 1e-4, 1e-10,
    1e10, 1e10, 1e-10,
    1e10, 1e-10, 1e-10,
    -10, -50, 10,
    -1e10, -1e10, 1e10,
    -1e-10, -1e-10, 1e-10 };

int main(int argc, char ** argv) {
  int i;
  for (i = 0 ; i < TEST_CASE_COUNT * 3 ; i += 3) {
    double first = f1(test_cases[i + 0], test_cases[i + 1], test_cases[i + 2]);
    double second = f2(test_cases[i + 0], test_cases[i + 1], test_cases[i + 2]);
    printf("For test case %d, the results were: %f, %f\n", i / 3, first, second);
  }
  printf("Ran %d test cases.\n", i / 3);
  return 0;
}
