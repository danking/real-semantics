/* You can include any desired C or C++ libraries */
#include <math.h>
#include "challenge.h"

/**
 * Welcome to your first day on the job of MAX_SPEED Rockets!
 *
 * Bad news! The MAX_SPEED PlusPlus Rocket is on a collision course with the
 * space station. The flight controller is reporting eroneous results for
 * certain trajectories. Your colleagues have isolated the fault to these pair
 * of functions, `f1` and `f2`. Unfortunately, your colleagues "were never good
 * at math" so they don't really know what this function does or why it
 * sometimes goes wrong.
 *
 * Since you're a freshly minted BS, they decided to take a lunch break and let
 * you sort it out. At least they left you a test suite that you can run with:
 *
 *     make test
 *
 * And they mentioned a tool called Real Semantics that you could use. It's
 * located here:
 *
 *     https://github.com/huangyihe/llvm-3.6.0/releases/tag/final-presentation-1.0
 *
 * You'll need to modify the `REAL_LLI` variable in `Makefile` to point to the
 * executable you downloaded. You should also have `clang` installed
 *
 * You can set the `HIDE_REFERENCE` macro to 0 to prevent the test harness from
 * printing (and thus Real Semantics from reporting errors on) the reference
 * implementation
 *
 * Also, the rocket, unless this code is fixed, will destroy the space station
 * in 10 minutes. Oh, and due to Bay's Rule it will then spontaneously destroy
 * Earth and the Universe.
 *
 * Have fun!
 */


double reference(double a, double b, double c) {
  double numerator = (-b-sqrt(b*b-4.0000000000000*a*c)); /* maximum zeros for maximum precision */
  double denominator = 2.0 * a;
  double result = numerator / denominator;
  return result;
}

/* SOLUTION */

double solution(double a, double b, double c) {
  double numerator = (-b-sqrt(b*b-4.0000000000000*a*c)); /* maximum zeros for maximum precision */
  double denominator = 2.0 * a;
  double result = numerator / denominator;
  return result;
  /* if (b < 0) { */
  /*   double numerator = 4*a*c; */
  /*   double denominator = (-b + sqrt(b*b - 4*a*c)) * 2*a; */
  /*   double result = numerator / denominator; */
  /*   return result; */
  /* } else if (0 <= b && b <= 10e127) { */
  /*   double numerator = -b - sqrt(b*b - 4*a*c); */
  /*   double denominator = 2*a; */
  /*   double result = numerator / denominator; */
  /*   return result; */
  /* } else    /\* b > 10^127 *\/{ */
  /*   return -b/a + c/b; */
  /* } */
}
