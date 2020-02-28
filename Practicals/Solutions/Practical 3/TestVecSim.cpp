#include "vecsim.h"
#include <iostream>
using namespace std;

int main_17()
{
	double vector1[10] = { 1.5, 3., 4.5, 6., 7.5, 9., 10.5, 12., 13.5, 15. };
	double vector2[10] = { 3., 4.5, 6., 7.5, 9., 10.5, 12., 13.5, 15., 16.5 };

	vecsim vs(vector1, vector2, 10);

	cout << "Euclidean dis = " << vs.Euclidean() << endl;
	cout << "Cosine sim = " << vs.Cosine() << endl;

	vecsim vs2;

	cout << "Euclidean dis = " << vs2.Euclidean(vector1, vector2, 10) << endl;
	cout << "Cosine sim = " << vs2.Cosine(vector1, vector2, 10) << endl;

	return 0;
}
