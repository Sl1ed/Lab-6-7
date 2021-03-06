#include "pch.h" 
#include <iostream> 
#include <stdio.h> 
#include <math.h> 
#include <cmath> 
double fun(double x) { return (12 * x * sqrt(x*x*x + 1)); }

int main()
{
	int n = 20;
	double x, x0 = -1, x1, xn = 1, h, f, y0, y1, y2, a0, a1, a2, L,
		t1 = 0, ht, N1, t2 = -2.0, N2, sum1, sum2, sum3, sum4, sum5, sum6,
		sum7, det1, det2, det3, det, P2;

	h = (xn - x0) / n;
	x1 = (x0 + xn) / 2;
	y0 = fun(x0);
	y1 = fun(x1);
	y2 = fun(xn);
	a0 = y0 / ((x0 - x1)*(x0 - xn));
	a1 = y1 / ((x1 - x0)*(x1 - xn));
	a2 = y2 / ((xn - x1)*(xn - x0));
	ht = 2.0 / n;
	sum1 = x0 + x1 + xn;
	sum2 = x0 * x0 + x1 * x1 + xn * xn;
	sum3 = pow(x0, 3) + pow(x1, 3) + pow(xn, 3);
	sum4 = pow(x0, 4) + pow(x1, 4) + pow(xn, 4);
	sum5 = y0 + y1 + y2;
	sum6 = x0 * y0 + x1 * y1 + xn * y2;
	sum7 = x0 * x0*y0 + x1 * x1*y1 + xn * xn*y2;
	det1 = sum5 * sum2*sum4 + sum1 * sum3*sum7 + sum2 * sum6*sum3 - sum2 * sum2*sum7 - sum3 * sum3*sum5 - sum4 * sum1*sum6;
	det2 = 21 * sum6*sum4 + sum5 * sum3*sum2 + sum2 * sum1*sum7 - sum2 * sum6*sum2 - sum3 * sum7 * 3 - sum4 * sum5*sum1;
	det3 = 21 * sum2*sum7 + sum1 * sum6*sum2 + sum5 * sum1*sum3 - sum5 * sum2*sum2 - sum6 * sum3 * 3 - sum7 * sum1*sum1;
	det = 21 * sum2*sum4 + sum1 * sum3*sum2 + sum2 * sum1*sum3 - sum2 * sum2*sum2 - sum3 * sum3 * 3 - sum4 * sum1*sum1;

	x = x0;
	printf("| i | xi | t | t1 | Yi | L2i | |Yi-L2i|| N1i | |Yi-N1i|| N2i | |Yi-N2i|| P2i | |Yi-P2i||\n");
	//printf("N X f(x) L(x) |f-L| t N1(x) |f-N1| t' N2(x) |f-N2| P2(x) |f-P2|\n"); 
	printf("-----------------------------------------------------------------------------------------------------------------------------------------\n");

	for (int i = 0; i <= n; i++)
	{
		f = fun(x);
		L = a0 * (x - x1)*(x - xn) + a1 * (x - x0)*(x - xn) + a2 * (x - x0)*(x - x1);
		N1 = y0 + t1 * (y1 - y0) + (t1*(t1 - 1)) / 2 * ((y2 - y1) - (y1 - y0));
		N2 = y2 + t2 * (y2 - y1) + (t2*(t2 + 1)) / 2 * ((y2 - y1) - (y1 - y0));
		P2 = det3 / det * x*x + det2 / det * x + det1 / det;
		//printf("%d %.2f %.3f %.3f %.4f %.3f %.3f %.4f %.3f %.3f %.4f %.3f %.4f\n", i, x, f, L, fabs(f - L), t1, N1, fabs(f - N1), t2, N2, fabs(f - N2), P2, fabs(f - P2)); 
		printf("| %d | %.2f | %.1f | % .1f | %.5f | %.5f | %.5f | %.5f | %.5f | %.5f | %.5f | %.5f | %.5f |\n", i, x, t1, t2, f, L, fabs(f - L), N1, fabs(f - N1), N2, fabs(f - N2), P2, fabs(f - P2));
		x = x + h;
		t1 = t1 + ht;
		t2 = t2 + ht;
	}
	getchar();
	return 0;
}