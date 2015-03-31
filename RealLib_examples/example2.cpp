#include <stdio.h>
#include <time.h>
#include "Real.h"

using namespace RealLib;

int main()
{

	char buf[100];
	clock_t starttime = clock();
	InitializeRealLib();

   {
      Real x("2");
      Real y = sqrt(x);

      printf("%s %s\n", x.AsDecimal(buf, 15), y.AsDecimal(buf, 15));
   }

   unsigned pr = FinalizeRealLib();

	clock_t endtime = clock();
	printf("prec: %d time elapsed: %lf\n", pr, 
double(endtime - starttime) / CLOCKS_PER_SEC);

   getchar();
	return 0;
}
