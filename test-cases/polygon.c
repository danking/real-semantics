#include <math.h>
#include <stdio.h>

/*
 *http://leafea.s3-website-us-east-1.amazonaws.com/writing/formula.pdf
 * We are given a point X and a simple polygon P with N vertices A1, A2, ..., An. We want to determine if X is inside P (exluding boundaries).
 */

int isInside(float x, float y, int n, float xs[], float ys[]) {
  float angle = 0;
  float ux = 0;
  float uy = 0;
  float vx = 0;
  float vy = 0;  
  for (int i = 0; i < n-1; i++) {
    ux = xs[i] - x;
    uy = ys[i] - y;
    vx = xs[i+1] - x;
    vy = ys[i+1] - y;
    angle += atan(uy/ux) - atan(vy/vx);
  }
  if (fabsf(angle) < 2 * M_PI) {
    return 1;
  }
  return 0;
}

int main(void) {
  float xs[] = {-10000000.0, 0.0, 10000000.0};
  float ys[] = {0.0, 0.01, 0.0};
  int result = isInside(0.0, 0.0, 3, xs, ys);
  printf("Answer: %d\n", result);
  return 0;
}
