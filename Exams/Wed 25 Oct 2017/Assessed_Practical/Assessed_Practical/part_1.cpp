/*
Name : Dewei Liu
Student No. 40216004
*/


#include "part_1.h"
int get_min(int a, int b, int c) {
	if (a < b) {
		if (a < c) {
			return a;
		}
		else {
			return c;
		}
	}
	else {
		if (b < c) {
			return b;
		}
		else {
			return c;
		}
	}
}

void rotate(double & x, double & y, double & z) {
	double first, second, third;
	first = x;
	second = y;
	third = z;
	y = first;
	z = second;
	x = third;
}