#include<iostream>
#include "test1.h"
using namespace std;
int Fib(int i) {
	if (i < 0) {
		return 0;
	}
	if (i == 0 || i == 0) {
		return 1;
	}
	return Fib(i - 1) + Fib(i - 2);
}

void test1() {
	for (int i = 0; i < 10; i++) {
		cout << "Fib(" << i << ") = " << Fib(i) << endl;
	}
}
