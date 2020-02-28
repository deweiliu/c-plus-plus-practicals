#include "Part_1.h"

int get_min(int a, int b, int c)
{
	// any algorithm that produces correct answer, such as below
	if (a <= b) {
		if (a <= c) return a;
		return c;
	}
	if (b <= c) return b;
	return c;
}

void rotate(double& x, double& y, double& z)
{
	double temp = y;
	y = x;
	x = z;
	z = temp;
}

// the C implementation
void rotate(double* x, double* y, double* z)
{
	double temp = *y;
	*y = *x;
	*x = *z;
	*z = temp;
}
