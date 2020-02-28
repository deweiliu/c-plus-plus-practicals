#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack(int size)
{
	stck_size = size;
	stck = new int[stck_size];
	tos = 0;
}

Stack::Stack(const Stack &st)
{
	stck = new int[st.stck_size];
	stck_size = st.stck_size;
	tos = st.tos;
	for (int i = 0; i < tos; i++)
		stck[i] = st.stck[i];
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


