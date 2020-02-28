#include "safe_array.h"
#include <iostream>
using namespace std;

// templae class safe array
int main()
{
	safe_array<int> i_array(10);	// create a 10-element int array
	i_array[5] = 5;					// in-bound accesses
	cout << i_array[5] << endl;
	i_array[-1] = 2;				// out-of-bound accesses
	cout << i_array[15] << endl;

	safe_array<double> d_array(20);	// create a 20-element double array
	for (int i = 0; i < 20; i++)	// in-bound access
		d_array[i] = sqrt(i);		
	cout << d_array[4] << endl;
	cout << d_array[20] << endl;	// out-of-bound access

	safe_array<char> c_array(26);	// create a 26-element char array
	for (int i = 0; i < 26; i++)	// in-bound access
		c_array[i] = 'a' + i;		
	cout << c_array[4] << endl;
	c_array[-3] = 'X';				// out-of-bound accesses

	return 0;
}
