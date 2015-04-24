#include <iostream>
#include <iomanip>
#include <cmath>

int main(int argc, char ** argv) {

  float * result = (float *) malloc(sizeof(float));

  * result = 42;

  printf("%f", * result);

  return 0;
}
