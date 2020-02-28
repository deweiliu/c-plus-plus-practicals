#include<iostream>
using namespace std;
#include"test1.h"
#include"test2.h"
#include"test3.h"

void main() {
	cout << "Test 1" << endl;
	test1();
	cout << endl;

	cout << "Test 2" << endl;
	test2();
	cout << endl;

	cout << "Test 3" << endl;
	test3();
	cout << endl;

	system("pause");
}