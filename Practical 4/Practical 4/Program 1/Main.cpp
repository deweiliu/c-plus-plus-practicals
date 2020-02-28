#include<iostream>
#include"Person.h"
using namespace std;
void main() {
	Person* a = new Person("David", "Li", "853", 1999);
	Person* b = new Person("Frank", "Wu", "852", 1996);
	if (*a <= *b) {
		cout << "Person a's ID is less or equal than b's." << endl;
	}
	else {
		cout << "Person a's ID is greater or equal than b's." << endl;

	}
	if (*a >= *b) {
		cout << "Person a's ID is greater or equal than b's." << endl;

	}
	else {
		cout << "Person a's ID is less or equal than b's." << endl;

	}
	delete a;
	delete b;
	system("pause");
}