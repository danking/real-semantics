#include <stdio.h>

float average(float * array, int length);

#define LENGTH 300

int main (int argc, char ** argv) {
  float array [LENGTH] = { 100000000
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 0.09, 0.09, 0.09
                         , 0.09, 0.09, 100000000
                         , 100000000};

  float sum = 0;
  for (int i = 0; i < LENGTH; ++i) {
    sum = sum + array[i];
  }
  float avg =  sum / LENGTH;

  printf("avg is %f\n", avg);
  return 0;
}
