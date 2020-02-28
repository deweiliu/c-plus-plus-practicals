#include<iostream>
#include "Functions.h"
using namespace std;
void get_array_value(int *a, int length, int position) {
	if (length > 0) {
		while (*a == INT_MIN) {
			cout << "Input the " << position << " th value : ";
			cin >> *a;
			if (cin.fail()) {
				cin.clear();
				char c;
				cin >> c;
			}
		}
		get_array_value(a + 1, length - 1, position + 1);
	}

}
void init_array_value(int *a, int length) {
	while (length > 0) {
		length--;
		*a = INT_MIN;
		a++;
	}
}
bool compare_array(int *a, int *b, int length) {
	if (length == 0) {
		return true;
	}
	int value_position = find_value(*a, b, length);
	if (value_position == INT_MIN) {
		return false;
	}
	else {
		remove_value(a, length, 0);
		remove_value(b, length, value_position);
		return compare_array(a, b, length-1);
	}
}


int find_value(int value, int*array, int length) {
	for (int i = 0; i < length; i++) {
		if (array[i] == value) {
			return i;
		}
	}
	return INT_MIN;
}
void remove_value(int*&array, int array_len, int pos) {
	if (array_len < 0) {
		cout << "Error! This array does not exist." << endl;
		system("pause");
		exit(0);
	}
	if (pos<0 || pos>array_len) {
		cout << "Error! This position given is out of rang." << endl;
	}
	else {
		int *new_array = (int*)malloc(sizeof(int)*array_len);
		if (new_array == NULL) {
			cout << "Error! There is no space to create a array.";
			system("pause");
			exit(0);
		}
		int i = 0;
		for (; i < pos; i++) {
			new_array[i] = array[i];
		}
		for (i++; i < array_len; i++) {
			new_array[i - 1] = array[i];
		}
		free(array);
		array = new_array;
		array_len--;
	}
}
void print_array(int *array, int length) {
	cout << "This array of "<<length<<" is : ";
	for (; length > 0; length--) {
		cout << *array << ", ";
		array++;
	}
	cout << "\b\b ";
	cout << endl;

}

int get_array_size() {
	int length = -1;
	while (length <= 0) {
		cout << "Input the array size : ";
		cin >> length;
		if (cin.fail()) {
			cin.clear();
			char c;
			cin >> c;
		}
	}
	return length;
}