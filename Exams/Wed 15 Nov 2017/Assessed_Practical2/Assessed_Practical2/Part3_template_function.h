#pragma once
#include<iostream>
using namespace std;
template <typename T>
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

