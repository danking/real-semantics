#include <stdio.h>

float average(float * array, int length);

int main (int argc, char ** argv) {
  float array [100] = { 10000000
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
                       , 0.09, 0.09, 0.09
                       , 10000000};

  int length = 100;
  float sum = 0;
  /* for (int i = 0; i < length; ++i) { */
  /*   sum = sum + *(array + i); */
  /* } */
  sum = sum + array[0];
  /* printf("%f\n", sum); */
  /* return sum / length; */
  /* float avg = average(array, 100); */
  float avg = sum / length;

  /* printf("%f\n", avg); */

  return 0;
}


/* float average(float * array, int length) { */
/*   float sum = 0; */
/*   for (int i = 0; i < length; ++i) { */
/*     sum = sum + *(array + i); */
/*   } */
/*   printf("%f\n", sum); */
/*   return sum / length; */
/* } */
