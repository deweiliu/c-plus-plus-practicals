#include "find_max.h"
#include <iostream>
using namespace std;

int main()
{
	// int array test
	int i_array_len = 10;
	int* i_array = new int[i_array_len];
	for (int i = 0; i < i_array_len; i++)
		i_array[i] = rand() % 1000;

	for (int i = 0; i < i_array_len; i++) cout << i_array[i] << " ";
	cout << "\nmax value at index " << find_max(i_array, i_array_len) << endl;

	// double array test
	int d_array_len = 20;
	double* d_array = new double[d_array_len];
	for (int i = 0; i < d_array_len; i++)
		d_array[i] = sqrt(rand() % 1000);

	for (int i = 0; i < d_array_len; i++) cout << d_array[i] << " ";
	cout << "\nmax value at index " << find_max(d_array, d_array_len) << endl;

	return 0;
}
