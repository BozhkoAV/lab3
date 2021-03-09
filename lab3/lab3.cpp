#include <iostream>
#include "euler.h"
#include "rkf45.h"
#include <math.h>

using namespace std;

void MyFunc(double t, double* y, double* dy)
{
	dy[0] = y[1];
	dy[1] = ((t + 1.0) / t) * y[1] + 2.0 * ((t - 1.0) / t) * y[0];
}

double exactSolution(double t) 
{
	return exp(2.0 * t);
}

void main()
{
	int Negn = 2; //число уравнений
	int iwork[30];
	double work[15];
	double Y0[2];
	Y0[0] = exp(2.0);
	Y0[1] = 2.0 * exp(2.0);
	double T0 = 1.0;
	double RE = 1e-10;
	double AE = 1e-10;
	int iflag = 1;
	double tout = 1.0;
	double h = 0.1;

	cout << "\t RKF45: \n";

	for (int i = 0; i <= 10; i++)
	{
		RKF45(MyFunc, Negn, Y0, &T0, &tout, &RE, &AE, &iflag, work, iwork);

		cout << endl;
		cout << "   Exact Solution = ";
		printf("%13.9f", exactSolution(tout));
		cout << "   Y[0] = "; 
		printf("%13.9f", Y0[0]);
		cout << "   Y[1] = ";
		printf("%13.9f", Y0[1]);
		cout << "   iflag = " << iflag << " ";
		cout << "   Error = ";
		printf("%13.10f", fabs(exactSolution(tout) - Y0[0]));
		cout << endl;

		tout += h;
	}

	Negn = 2;
	Y0[0] = exp(2.0);
	Y0[1] = 2.0 * exp(2.0);
	T0 = 1.0;
	tout = 1.0;
	h = 0.1;

	cout << "\n\t EULER_KOSHI METHOD: \n";
	for (int i = 0; i <= 10; i++)
	{
		euler(MyFunc, Negn, h, Y0, T0, tout);
		
		cout << endl;
		cout << "   Exact Solution = ";
		printf("%13.9f", exactSolution(tout));
		cout << "   Y[0] = ";
		printf("%13.9f", Y0[0]);
		cout << "   Y[1] = ";
		printf("%13.9f", Y0[1]);
		cout << "   Error = ";
		printf("%13.10f", fabs(exactSolution(tout) - Y0[0]));
		cout << endl;

		tout += h;
		Y0[0] = exp(2.0);
		Y0[1] = 2.0 * exp(2.0);
	}
}