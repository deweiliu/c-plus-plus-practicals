#include"Matrix.h"

#include<iostream>

using namespace std;
template<typename T>
void  print_matrix(matrix<T> &  matrix) {
	cout << "The matrix : " << endl;
	for (int i = 0; i < matrix.get_rows(); i++) {
		for (int j = 0; j < matrix.get_cols(); j++) {
			cout << matrix[i][j] << "\t";

		}
		cout << endl;
	}

}
void main() {
	//dimensions of a matrix
	const int nRows = 3, nCols = 3;

	//create an interger matrix of nRows x nCols
	matrix<int> a(nRows, nCols);

	//set the matrix with random values
	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCols; j++) {
			a[i][j] = rand() % 100;
		}
	}


	//print the matrix
	print_matrix(a);
	cout << endl;
	/***********************************************/

	//create two nRows x nCols double matrices
	matrix<double> x(nRows, nCols);
	x[0][0] = 1; x[0][1] = 2; x[0][2] = 3;
	x[1][0] = 0; x[1][1] = 1; x[1][2] = 4;
	x[2][0] = 5; x[2][1] = 6; x[2][2] = 0;

	matrix<double> y(nRows, nCols);
	y[0][0] = -24; y[0][1] = 18; y[0][2] = 5;
	y[1][0] = 20; y[1][1] = -15; y[1][2] = -4;
	y[2][0] = -5; y[2][1] = 4; y[2][2] = 1;

	//matrix addition : u= x+y
	matrix <double>u = x + y;
	print_matrix(u);
	cout << endl;
	/***********************************************/

	//matrix multiplication: v= x* y
	matrix<double>v = x*y;
	print_matrix(v);

	cout << endl;
	/***********************************************/



	system("pause");
}