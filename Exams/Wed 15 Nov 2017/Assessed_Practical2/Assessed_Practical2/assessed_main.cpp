/*
Dewei Liu
40216004
CSC2040 Assessed_Practical2
Wed 15 Nov 2017
*/

#include <iostream>
#include "xarray.h"
#include"Part3_template_function.h"
#include"uConvert.h"
using namespace std;

int main1()
{
	xArray array(3);
	for (int i = 0; i < 3; i++) array.data[i] = i;

	if (array.size > 0) {
		xArray array2 = array;
	}
	cout << array.data[0];
	system("pause");
	return 0;
}
int main2() {
	xArray a(2);
	a.data[0] = 10; a.data[1] = 10;
	xArray b(3);
	b.data[0] = 4; b.data[1] = 9; b.data[2] = 5;
	if (a >= b) {
		cout << "a >= b is true" << endl;
	}
	if (b >= a) {
		cout << "b >= a is false" << endl;

	}

	system("pause");
	return 0;
}

int main3() {
	//1.	Declare an int variable array_len and initialize it to a value of 10.  
	int array_len = 10;

	//2.	Allocate a double array of size array_len by using new.
	double* double_array = new double[array_len];

	//	3.	Fill the array with arbitrary values.
	for (int i = 0; i < array_len; i++) {
		double_array[i] = (double)i;
	}

	//	4.	Print the values of the array.
	cout << "Array before remove: ";
	for (int i = 0; i < array_len; i++) {
		cout << double_array[i] << " ";
	}
	cout << endl;

	//	5.	Call the template function remove to remove the value at position 5.
	remove(double_array, array_len, 5);

	//	6.	Print the values of the new array.
	cout << "Array after remove: ";
	for (int i = 0; i < array_len; i++) {
		cout << double_array[i] << " ";
	}
	cout << endl;

	//	7.	Repeat Steps 1 - 6 to test the function with a char array.
	int array_len_for_char = 10;
	char* char_array = new char[array_len_for_char];
	for (int i = 0; i < array_len_for_char; i++) {
		char_array[i] = (char)(i + 97);
	}
	cout << "Array before remove: ";
	for (int i = 0; i < array_len_for_char; i++) {
		cout << char_array[i] << " ";
	}
	cout << endl;
	remove(char_array, array_len_for_char, 5);
	cout << "Array after remove: ";
	for (int i = 0; i < array_len_for_char; i++) {
		cout << char_array[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
int main()
{
	// a base class pointer
	uConvert* base_ptr = 0;

	// menu to take input from the users
	cout << "\nEnter 1 for litre to gallon conversion\n"
		<< "Enter 2 for Fahrenheit to Celsius conversion\n"
		<< "Enter 3 for feet to meter conversion\n"
		<< "Enter 4 for pound to kilogram conversion\n";
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
	case 4:
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
	system("pause");
	return 0;
}
