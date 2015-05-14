#include <stdio.h>
#include "challenge.h"

#define TEST_CASE_COUNT 9

double test_cases [TEST_CASE_COUNT * 3] =
  { 1, 1, 1,
    10, 10, 10,
    1e10, 1e10, 1e10,
    1e-10, 1e-10, 1e-10,
    1e10, 1e10, 1e-10,
    1e10, 1e-10, 1e-10,
    -10, -10, 10,
    -1e10, -1e10, 1e10,
    -1e-10, -1e-10, 1e-10 };

int main(int argc, char ** argv) {
  for (int i = 0 ; i < TEST_CASE_COUNT ; i += 3) {
    f1(test_cases[i + 0], test_cases[i + 1], test_cases[i + 2]);
    f2(test_cases[i + 0], test_cases[i + 1], test_cases[i + 2]);
  }
  return 0;
}
