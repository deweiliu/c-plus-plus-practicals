#include<ctime>
#include<Windows.h>
#include<iostream>
#include "Source.h"
#include<vector>
using namespace std;
double average(vector<int>&a, int n) {
	double av = 0;
	for (int i = 0; i < n; i++) {
		av += a[i]; Sleep(1);

	}


	av /= n;

	return av;
}

int numberOfAbove(vector<int>&a, int n, double aver)
{

	int number = 0;
	for (int i = 0; i < n; i++) {
		Sleep(1);
		if (a[i] > aver) {
			number++;
		}
	}return number;

}void main() {
	while (true) {
		cout << "Hello, please input N = ";
		int n;
		cin >> n;
		vector<int> a(0);
		srand((unsigned)time(NULL));
		for (int i = 0; i < n; i++) {
			a.push_back(rand());
		}

		clock_t start = clock();
		double aver = average(a, n);
		clock_t end = clock();
		clock_t elapsed = end - start;
		cout << "Hello, average is " << aver << " elapsed time is " << elapsed << " ms." << endl;


		start = clock();
		int number = numberOfAbove(a, n, aver);
		end = clock(); elapsed = end - start;
		cout << "Hello, there are " << number << " elements greater than the average of " << aver << ". elapsed time is " << elapsed << " ms." << endl;




	}system("pause");
}