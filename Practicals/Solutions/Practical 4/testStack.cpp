#include "Stack.h"
#include <iostream>
using namespace std;

void f(Stack &a)
{
	Stack b = a;
}

int main()
{
	Stack s(2);
	s.push(4);
	s.push(13);
	f(s);
	cout << s.pop() << endl;
	return 0;
}