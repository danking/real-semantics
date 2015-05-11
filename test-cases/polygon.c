#include <math.h>
#include <stdio.h>

/*
 * http://leafea.s3-website-us-east-1.amazonaws.com/writing/formula.pdf
 * We are given a point X and a simple polygon P with N vertices A1, A2, ..., An. We want to determine if X is inside P (exluding boundaries).
 */

int isInside(float x, float y, int n, float xs[], float ys[]) {
  float angle = 0;
  float ux, uy, vx, vy;
  for (int i = 0; i < n; i++) {
    ux = xs[i] - x;
    uy = ys[i] - y;
    vx = x - xs[(i+1)%n];
    vy = y - ys[(i+1)%n];
    angle += atan2f(uy,ux) - atan2f(vy,vx);
  }
  return (fabsf(angle) <= 2*M_PI);
}

int isInsideImp(float x, float y, int n, float xs[], float ys[]) {
  float angle = 0;
  float ux, uy, vx, vy;
  for (int i = 0; i < n; i++) {
    ux = xs[i] - x;
    uy = ys[i] - y;
    vx = x - xs[(i+1)%n];
    vy = y - ys[(i+1)%n];
    angle += (ux*vx + uy*vy)/(sqrt(pow(ux,2) + pow(uy,2)) * sqrt(pow(vx,2) + pow(vy,2)));
  }
  return (fabsf(angle) <= 2*M_PI);
}

int main(void) {
  float xs[] = {-0.00001, 0, 0.00001};
  float ys[] = {0, 0.00001, 0};
  int n = 3;
  float testx = 0;
  float testy = 0.0000101;

  int result = isInsideImp(testx, testy, n, xs, ys);
  printf("Imprecise Algorithm: %d\n", result);
  result = isInside(testx, testy, n, xs, ys);
  printf("More Precise Algorithm: %d\n", result);
  return 0;
}
