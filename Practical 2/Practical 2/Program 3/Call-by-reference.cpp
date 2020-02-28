#include<string>
#include<iostream>
#include "Call-by-reference.h"
using namespace std;
void insert(int *&array, int &array_len, int pos, int val) {
	if (array_len < 0) {
		cout << "Error! This array does not exist." << endl;
		system("pause");
		exit(0);
	}
	if (pos<0 || pos>array_len) {
		cout << "Error! This position given is out of rang." << endl;

	}
	else {
		array_len++;
		int *new_array = new int[array_len];// (int*)malloc(sizeof(int)*array_len);
		if (new_array == NULL) {
			cout << "Error! There is no space to create a array.";
			system("pause");
			exit(0);
		}
		int i = 0;
		for (; i < pos; i++) {
			new_array[i] = array[i];
		}
		new_array[i] = val;
		for (i++; i < array_len; i++) {
			new_array[i] = array[i - 1];
		}
		free(array);
		array = new_array;
	}
}

void remove(int*&array, int &array_len, int pos) {
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
void print(int*array, int array_len) {
	cout << endl << "The array is : ";
	for (int t = 0; t < array_len; t++) {
		cout << *array++ << ", ";
	}
	if (array_len) {
		printf("\b\b \n");
	}

}
