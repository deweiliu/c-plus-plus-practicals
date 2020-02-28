#include<iostream>
#include "Source.h"
#include<ctime>
#define N 100
using namespace std;
void main() {
	int a[N];

	//First test
	for (int i = 0; i < N; i++) {
		a[i] = 3 * i + 1;
	}
	if (isSorted(a, N)) {
		cout << "Hello, this array is sorted." << endl;
	}
	else {
		cout << "Hello, this array is NOT sorted." << endl;
	}

	//Second test
	srand((unsigned)time(nullptr));
	for (int i = 0; i < N; i++) {
		a[i] = rand() % 1000;
	}
	if (isSorted(a, N)) {
		cout << "Hello, this array is sorted." << endl;
	}
	else {
		cout << "Hello, this array is NOT sorted." << endl;
	}

	system("pause");


}
bool isSorted(int* a, int n) {
	for (int i = 0; i < n - 1; i++) {
		if ((a[i] > a[i + 1])) {
			return false;
		}
	}return true;
}