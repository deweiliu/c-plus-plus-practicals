#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack(int size)
{
	stck_size = size;
	stck = new int[stck_size];
	tos = 0;
}

Stack::Stack(const Stack &a) {
	stck_size = a.stck_size;
	stck = new int[stck_size];
	tos = 0;
	for (int i = 0; i < a.tos; i++) {
		push(a.stck[i]);
	}
}

Stack::~Stack()
{
	delete[]stck;
}

void Stack::push(int i)
{
	if (tos == stck_size) {
		cout << "Stack overflow" << endl;
		return;
	}
	stck[tos++] = i;
}

int Stack::pop()
{
	if (tos == 0) {
		cout << "Stack underlow" << endl;
		return 0;
	}
	return stck[--tos];
}


