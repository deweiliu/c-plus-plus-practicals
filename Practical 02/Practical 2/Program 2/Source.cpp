#include<string>
#include<iostream>
using namespace std;
void main() {
	int i = 27;
	int *i_ptr = &i;
	cout << "value in i is " << i << endl;
	cout << "address of i is " << i_ptr << endl;
	cout << "value from dereferencing pointer is " << *i_ptr << endl;

	*i_ptr = 35;
	cout << "value in i is " << i << endl;

	double*d_ptr = NULL;
	cout << "value in pointer is " << d_ptr << endl;

	//*d_ptr = 0.25; Error, NULL is not a valid memory address
	double d;
	d_ptr = &d;

	if (d_ptr != NULL) {
		*d_ptr = 0.25;
	}
	cout << "value of d is " << d << endl;
	system("pause");
}