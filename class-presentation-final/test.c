#include <stdio.h>
#include "challenge.h"

#define TEST_CASE_COUNT 15
#define HIDE_REFERENCE 1

double test_cases [TEST_CASE_COUNT * 3] =
  { 100           , -8356218543e201   , -321432,  // 0
    100           , -8356218543e23    , -321432,  // 1
    -21343243e5   , -3421893e57       , 729e22,   // 2
    -10           , -50               , 10,       // 3
    -1e10         , -1e10             , 1e10,     // 4
    -1e-10        , -1e-10            , 1e-10,    // 5
    3.214323e-201 , 5e-100            , 1.32423,  // 6
    1e-10         , 1e-4              , 1e-10,    // 7
    1             , 3                 , 2.25,     // 8
    1             , 10                , 1,        // 9
    1e10          , 1e11              , 1e10,     // 10
    -342e57       , 1e10              , 1e-10,    // 11
    98045376e102  , 432789658e201     , 42e-42,   // 12
    4328973e5     , 432789658e201     , 2134e2,   // 13
    4328973e202   , 432789658e201     , 2134e2    // 14
  };

int main(int argc, char ** argv) {
  int i;
  for (i = 0 ; i < TEST_CASE_COUNT * 3 ; i += 3) {
    double ref = reference(test_cases[i + 0], test_cases[i + 1], test_cases[i + 2]);
    double soln = solution(test_cases[i + 0], test_cases[i + 1], test_cases[i + 2]);

    if (HIDE_REFERENCE) {
      printf("For test case %2d, the reference implementation was: %.16e\n", i / 3, ref);
      printf("                            your solution produced: %.16e\n", soln);
    } else {
      printf("For test case %2d, your solution produced: %.16e\n", i / 3, soln);
    }
  }
  printf("Ran %d test cases.\n", i / 3);
  return 0;
}
