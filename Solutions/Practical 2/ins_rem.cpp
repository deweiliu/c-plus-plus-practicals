//Program 4
#include "ins_rem.h"
#include <iostream>
using namespace std;

void insert(int* &array, int &array_len, int pos, int val)
{
	if (!array || array_len <= 0) {
		cout << "invalid array" << endl;
		return;
	}
	if (pos < 0 || pos >= array_len) {
		cout << "pos is out of range" << endl;
		return;
	}

	// new array length after insertion
	array_len++;
	// new array
	int* temp = new int[array_len];
	for (int i = 0; i < pos; i++) temp[i] = array[i];
	temp[pos] = val;
	for (int i = pos + 1; i < array_len; i++) temp[i] = array[i - 1];

	// delete original array
	delete[] array;
	// set the new array
	array = temp;
}

void remove(int* &array, int &array_len, int pos)
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
	int* temp = new int[array_len];
	for (int i = 0; i < pos; i++) temp[i] = array[i];
	for (int i = pos; i < array_len; i++) temp[i] = array[i + 1];

	// delete original array
	delete[] array;
	// set the new array
	array = temp;
}
