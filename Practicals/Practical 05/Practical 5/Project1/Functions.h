#pragma once
#include<ctime>
#include<iostream>
template <typename T>
void random_assign(T &array, int length);
template <typename T>
void show_array(T const &array, int length);

template <typename T>
void random_assign(T &array, int length) {
	srand((unsigned)time(NULL));
	for (int i = 0; i < length; i++) {
		array[i] = rand() % 100;
	}
}
template <typename T>

void show_array(T &array, int length) {
	for (int i = 0; i < length; i++) {
		cout << array[i] << '\t';
	}
	cout << endl;
}