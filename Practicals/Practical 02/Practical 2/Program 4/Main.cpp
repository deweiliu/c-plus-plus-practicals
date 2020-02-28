#include<iostream>
#include"Functions.h"
using namespace std;
void main() {

	int length = get_array_size();

	int* a = new int[length];
	int* b = new int[length];

	init_array_value(a, length);
	init_array_value(b, length);

	get_array_value(a, length, 0);
	get_array_value(b, length, 0);

	print_array(a, length);
	print_array(b, length);

	if (compare_array(a, b, length)) {
		cout << "This two arrays have the same elements." << endl;
	}
	else {
		cout << "This two arrays do not have the same elements." << endl;

	}
	system("pause");
}