/*
 * Floating-point arithmetic may give inaccurate results in Excel
 * https://support.microsoft.com/en-us/kb/78113
 */

#include<stdio.h>

/*
 * "Example Using Very Large Numbers"
 */
int veryLarge(void) {
  float A1 = 1.2E+30;
  float B1 = 1E+15;
  float C1 = A1+B1;
  if (A1 == C1) {
    printf("A1 and C1 are equal.\n");
  } else {
    printf("A1 and C1 are not equal.\n");
  }
  return 1;
}

/*
 * "Example Using Very Small Numbers"
 */
int verySmall(void) {
  float A1 = 0.000123456789012345;
  float B1 = 1;
  float C1 = A1+B1;
  printf("%.10f\n", C1);
  return 1;
}

/*
 * "Repeating Binary Numbers and Calculations with Results Close to Zero"
 */
int mySum(void) {
  float sum = 0;
  for (int i = 0; i < 10000; i++) {
    sum += 0.0001;
  }
  printf("%.10f\n", sum);
  return 1;
}

/*
 * "Example Adding a Negative Number"
 */
int negNumber(void) {
  float A1 = (43.1 - 43.2);
  A1 += 1;
  printf("%.10f\n", A1);
  return 1;
}

/*
 * Example When a Value Reaches Zero
 */
int reachZero(void) {
  float A1 = 1.333;
  A1 += 1.225;
  A1 -= 1.333;
  A1 -= 1.225;
  printf("%.10f\n", A1);
  return 1;
}

int main(void) {
  veryLarge();
  verySmall();
  mySum();
  negNumber();
  reachZero();
  return 0;
}
