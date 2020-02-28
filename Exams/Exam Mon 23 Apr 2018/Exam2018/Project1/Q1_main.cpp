#include<iostream>
#include<string>
#include "Q1_main.h"
#include"myClass.h"
using namespace std;

template <class T>
void test1(const T& expected, const T &actual, const string& description = "") {
	cout << "Test for " << description << ": ";
	if (expected == actual) {
		cout << "Passed";
	}
	else {
		cout << "Failed";
	}
	cout << endl << "\tExpected: " << expected << "\tActual: " << actual << endl << endl;
}

void main() {
	//(a)
	test1(6., myFunc(3), "Test for (a)");
	test1(1.0 / 1 + 1.0 / 2 + 1.0 / 3, myFunc(-3), "Test for (a)");
	test1(0., myFunc(0), "Test for (a)");

	//(b)
	myClass a(10, 11);
	test1(11, a.max_number(), "Test for (b)");

	myClass b(4, 9);
	test1(9, b.max_number());

	test1(true, a >= b);
	test1(true, a >= a);
	test1(false, b >= a);

	//(c)
	myClass* o = new myClass[100];
	delete[]o;

	system("pause");
}

double myFunc(int n) {
	double result = 0;
	if (n > 0) {
		for (int i = 1; i <= n; i++) {
			result += i;
		}
	}
	else {
		if (n < 0) {
			for (int i = 1; i <= -n; i++) {
				result += ((double)1 / i);
			}
		}
		else {
			result = 0;
			cout << "The parameter is invalid.\n";
		}
	}
	return result;
}