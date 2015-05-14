#include <stdio.h>
#include <math.h>

void form1(double a, double b, double c) {
  double result = 4.0*a*c/(-b + sqrt(b*b-4.0*a*c))/(2.0*a);
  printf("form 1 evaluates to: %.15f\n", result);
}

void form2(double a, double b, double c) {
  double result = (-b-sqrt(b*b-4.0*a*c))/(2.0*a);
  printf("form 2 evaluates to: %.15f\n", result);
}

int main() {
  double a, b, c;
  a = 1.23;
  b = -3740.7;
  c = 0.74;

  form1(a, b, c);
  form2(a, b, c);

  return 0;
}
