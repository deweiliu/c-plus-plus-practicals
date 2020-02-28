#include<string>
#include<iostream>
#include<conio.h>
#include "Call-by-reference.h"
#include"Source1.h"
using namespace std;
void main() {
	int array_len = 0, length, value;
	int*array = NULL;
	cout << "Please enter the number of volumn of array : ";
	cin >> length;
	cout << "Please enter values of array one by one : " << endl;
	for (int t = 0; t < length; t++) {
		cin >> value;
		insert(array, array_len, t, value);
	}
	do {
		print(array, array_len);
	} while (function(array, array_len));


}