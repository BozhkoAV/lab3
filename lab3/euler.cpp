# include"euler.h"
# include<math.h>
# include<stdlib.h>

void euler (void (*F) (double t1, double *y1, double* dy1), int n, double h, double *y, double t, double tout)
{
	double *yp = new double[n],
		*Y = new double[n];
	     double nyp[2];

	int i;
	while (t<tout)
	{
		Y[0]=y[0];        
		Y[1]=y[1];
		F(t, y, yp);
		nyp[0]=yp[0];
		nyp[1]=yp[1];
		for (i=0; i<n; i++)
		{
			y[i]=Y[i]+h*yp[i];
		}

		F(t+h, y, yp);
		for (i=0; i<n; i++)
		{
			y[i]=Y[i]+(h/2.0)*(yp[i]+nyp[i]);
            /*y[i]=Y[i]+(h/2.0)*(yp[i]);*/
		}
		t=t+h;
	}
	delete[] yp, Y;
	return;
}