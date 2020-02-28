#include<iostream>
using namespace std;
#define ROW 10
#define COLUMN 20

void print(int**a, int row, int column) {
	cout << a[row][column] << endl;
}

void main() {
	int **a = new int*[ROW];
	for (int i = 0; i < ROW; i++) {
		a[i] = new int[COLUMN];
	}
	a[2][3] = 11;
	print(a, 2, 3);
	for (int i = 0; i < ROW; i++) {
		delete[] a[i];
	}
	delete[] a;
	system("pause");
}
