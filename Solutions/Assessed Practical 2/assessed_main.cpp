#include <iostream>
#include "xarray.h"
#include "uConvert.h"
using namespace std;

int main()
{
	// a base class pointer
	uConvert* base_ptr = 0;

	// menu to take input from the users
	cout << "\nEnter 1 for litre to gallon conversion\n"
		<< "Enter 2 for Fahrenheit to Celsius conversion\n"
		<< "Enter 3 for feet to meter conversion\n"
		<< "Enter 4 for pounds to kilograms conversion\n";	/*** Extension: new menu item ***/
	int option;
	cin >> option;

	// pointing base_ptr to the derived object of the user's choice
	switch (option) {
	case 1:
		base_ptr = new l2g;
		break;
	case 2:
		base_ptr = new f2c;
		break;
	case 3:
		base_ptr = new f2m;
		break;
	case 4:						/*** Extension: case 4 ***/
		base_ptr = new p2k;
		break;
	default:
		return 0;
	}

	// invoking the conversion
	base_ptr->read_unit();
	base_ptr->convert();
	base_ptr->print();

	delete base_ptr;
	return 0;
}

template<typename T>
void remove(T* &array, int &array_len, int pos)
{
	if (!array || array_len <= 1) {
		cout << "invalid array" << endl;
		return;
	}
	if (pos < 0 || pos >= array_len) {
		cout << "pos is out of range" << endl;
		return;
	}
	// new array length after removal
	array_len--;
	// new array
	T* temp = new T[array_len];
	for (int i = 0; i < pos; i++) temp[i] = array[i];
	for (int i = pos; i < array_len; i++) temp[i] = array[i + 1];
	// delete original array
	delete[] array;
	// set the new array
	array = temp;
}

int main3()
{
	int array_len = 10;

	// double d_array
	double* d_array = new double[array_len];
	// populate d_array with arbitrary values e.g. 
	for (int i = 0; i < array_len; i++)
		d_array[i] = i;
	// before remove
	for (int i = 0; i < array_len; i++)
		cout << d_array[i] << " ";
	cout << endl;
	// call remove
	remove(d_array, array_len, 5);
	// after remove
	for (int i = 0; i < array_len; i++)
		cout << d_array[i] << " ";
	cout << endl;
	// delete d_array
	delete[] d_array;	

	// char array
	array_len = 10;
	char* c_array = new char[array_len];
	// populate c_array with arbitrary values e.g. 
	for (int i = 0; i < array_len; i++)
		c_array[i] = 'a' + i;
	// before remove
	for (int i = 0; i < array_len; i++)
		cout << c_array[i] << " ";
	cout << endl;
	// call remove
	remove(c_array, array_len, 5);
	// after remove
	for (int i = 0; i < array_len; i++)
		cout << c_array[i] << " ";
	cout << endl;
	// delete c_array
	delete[] c_array;

	return 0;
}

int main2()
{
	// arrays a
	xArray a(2);
	a.data[0] = 10; a.data[1] = 10;

	// arrays b
	xArray b(3);
	b.data[0] = 4; b.data[1] = 9; b.data[2] = 5;

	if(a >= b) 
		cout << "a >= b is true" << endl;

	if(b >= a) 
		cout << "b >= a is true" << endl;
	else 
		cout << "b >= a is false" << endl;
	// OR
	if (!(b >= a))
		cout << "b >= a is false" << endl;

	return 0;
}

int main1()
{
	xArray array(3);
	for (int i = 0; i < 3; i++)
		array.data[i] = i;

	if (array.size > 0) {
		xArray array2 = array;
	}
	cout << array.data[0];

	return 0;
}
