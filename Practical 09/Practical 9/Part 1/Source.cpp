#include<ctime>
#include<Windows.h>
#include<iostream>
#include "Source.h"
using namespace std;
void main() {
	clock_t start = clock();
	timeTesting();
	clock_t end = clock();
	clock_t elapsed = end - start;
	cout << "Hello, elapsed is " << elapsed << " ms." << endl;

	start = clock();
	timeTesting();
	end = clock();
	elapsed = end - start;
	cout << "Hello, elapsed is " << elapsed << " ms." << endl;

	system("pause");
}
void timeTesting() {
	for (int i = 0; i < 1000; i++) {
		Sleep(1);
	}
}