#include<Windows.h>
#include<iostream>
#include<ctime>
#include<random>
using namespace std;
#include<vector>
#include "Source.h"
void main() {
	int const N = 10;
	int b[N] = { 5, 8, 33, 16, 14, 56, 50, 5,12,123 };
	cout << "Original array\n" << endl;
	for (int i = 0; i < N; i++) {
		cout << b[i] << " ";
	}
	clock_t start = clock();
	insertionSort(b, N - 1);
	clock_t end = clock();
	clock_t elapsed = end - start;
	cout << "Sorted array" << endl;
	for (int i = 0; i < N; i++) {
		cout << b[i] << " ";
	}
	cout << "\nElapsed time is " << elapsed << endl;
	system("pause");
}

void insertionSort(int *a, int total) {
	for (int i = 0; i < total; i++) {
		int current = i;
		int temp = a[current];

		int position = 0;
		while (position < current&&a[position] < temp) {
			position++;
			Sleep(1);
		}
		while (current > position) {
			a[current] = a[current - 1];
			current--;
		}a[current] = temp;
	}
}