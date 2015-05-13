#include<stdio.h>

/*
 * P(A union B) = P(A) + P(B) - P(A)P(B)
 */
int direct(float p, float q) {
  float ans = p + q - p * q;
  printf("P(A union B) = P(A) + P(B) - P(A)P(B) = %.10f\n", ans);
  return 1;
}

/*
 * P(A union B) = 1 - (1 - P(A))(1 - P(B))
 */ 
float complement(float p, float q) {
  float ans = 1 - (1 - p)*(1 - q);
  printf("P(A union B) = 1 - (1 - P(A))(1 - P(B)) = %.10f\n", ans);
  return 1;
}

/*
 * Calculates P(A union B) using two mathematically equivalent methods.
 */
int main (void) {
  float p = 0.000009;
  float q = 0.00000008;

  printf("P(A) = %.6f\nP(B) = %.8f\n", p, q);

  direct(p, q);
  complement(p, q);
}
