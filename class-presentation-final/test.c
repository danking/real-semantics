#include <stdio.h>
#include "challenge.h"

#define TEST_CASE_COUNT 14

double test_cases [TEST_CASE_COUNT * 3] =
  { 100           , -8356218543e23    , -321432,  // 0
    -21343243e5   , -3421893e57       , 729e22,   // 1
    -10           , -50               , 10,       // 2
    -1e10         , -1e10             , 1e10,     // 3
    -1e-10        , -1e-10            , 1e-10,    // 4
    1e-10         , 1e-4              , 1e-10,    // 5
    1             , 3                 , 2.25,     // 6
    1             , 10                , 1,        // 7
    10            , 100               , 10,       // 8
    1e10          , 1e11              , 1e10,     // 9
    1e10          , 1e10              , 1e-10,    // 10
    -342e57       , 1e10              , 1e-10,    // 11
    98045376e102  , 432789658e201     , 42e-42,   // 12
    4328973e5     , 432789658e201     , 2134e2    // 13
  };

int main(int argc, char ** argv) {
  int i;
  for (i = 0 ; i < TEST_CASE_COUNT * 3 ; i += 3) {
    double first = f1(test_cases[i + 0], test_cases[i + 1], test_cases[i + 2]);
    double second = f2(test_cases[i + 0], test_cases[i + 1], test_cases[i + 2]);
    printf("For test case %d, the results were: %.16f, %.16f\n", i / 3, first, second);
  }
  printf("Ran %d test cases.\n", i / 3);
  return 0;
}
