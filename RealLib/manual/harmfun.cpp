#include <iostream>
#include <iomanip>
#include <ctime>
#include "Real.h"

using namespace RealLib;
using namespace std;

#define LENGTH 1000000
#define MACROTOSTRING2(x) # x
#define MACROTOSTRING(x) MACROTOSTRING2(x)

template <class TYPE>
TYPE Harmonic(const long prec, const long mcnt)
{
	TYPE one(1);
	TYPE s;	// initialized to 0
	for (int i=1; i<=mcnt; ++i) {
		s += one/i;
	}
	return s;
}
CreateIntRealFunction(Harmonic);


int main()
{
	clock_t starttime, endtime;
	
	cout << "Computing the sum for " MACROTOSTRING(LENGTH) " members" << endl;

	starttime = clock();
	InitializeRealLib();
	{
		Real h(Harmonic(LENGTH));
		endtime = clock();
		cout << "construction time: " <<
			double(endtime - starttime) / CLOCKS_PER_SEC << endl;

		for (int n=9; n<500; n*=7) {
			starttime = clock();
			cout << unitbuf << setprecision(n);
			cout << n <<" digits: \t" << h << endl;
			endtime = clock();
			cout << setprecision(6);
			cout << "prec: " << GetCurrentPrecision() << " time elapsed: " << 
				double(endtime - starttime) / CLOCKS_PER_SEC << endl;
		}
		starttime = clock();
	}
	FinalizeRealLib();
	endtime = clock();
	cout << "destruction time: " <<
		double(endtime - starttime) / CLOCKS_PER_SEC << endl;


	return 0;
}
