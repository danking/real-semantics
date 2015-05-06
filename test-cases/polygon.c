#include <math.h>

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
  float xs[] = {-1.0, -0.1, 1.0};
  float ys[] = {-0.1, 1.0, -0.1};
  isInside(0.0001, 0.0001, 3, xs, ys);  
  return 0;
}
