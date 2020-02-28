#include<iostream>
#include<string>
#include<ctype.h>
#include"ArrayStack.h"
using namespace std;
template <typename T>
void setUpStack(ArrayStack<T>* s, int num) {
	string a;
	while (num > 0) {
		num--;
		cin >> a;
		s->push(a);
	}
}
template <typename T>
void printStack(ArrayStack<T>& s) {
	cout << "The stack is : " << endl;
	ArrayStack<T> x;
	while (!s.isEmpty()) {
		x.push(*(s.pop()));
		cout << *(x.top()) << '\t';
	}
	while (!x.isEmpty()) {
		s.push(*(x.pop()));
	}
	cout << endl;
}

template <typename T>
void removeAt(ArrayStack<T>& s, int p) {
	if (p > s.size()) {
		cout << "There is no item in this position" << endl;
		return;
	}
	ArrayStack<T> x;
	while (s.size() > p + 1) {
		x.push(*(s.pop()));
	}
	s.pop();
	while (!x.isEmpty()) {
		s.push(*(x.pop()));
	}
}

bool isoperator(char x) {
	switch (x) {
	case '+':case '-':case '*':case'/':return true;
	default: return false;
	}
}
void evaluateExpression() {	string s;	getline(cin, s);	ArrayStack<double> stack;	int i = 0;	while (s[i] != '#') {		if (isdigit(s[i])) {			int value = 0;			while (isdigit(s[i])) {				value *= 10;				value += (s[i] - 48);				i++;			}			stack.push(value);		}		if (isoperator(s[i])) {			switch (s[i]) {			case '+':stack.push(*(stack.pop()) + *(stack.pop())); break;
			case '-':stack.push(-*(stack.pop()) + *(stack.pop()));  break;
			case '*':stack.push(*(stack.pop()) * *(stack.pop())); break;
			case '/':stack.push(1 / (*(stack.pop())) *(*(stack.pop()))); break;
			}		}		i++;	}	cout << "= " << *(stack.pop());}

void main() {
	ArrayStack<string>* s = new ArrayStack<string>;
	cout << "Array Stack:" << endl;
	evaluateExpression(); 	cout << endl;	setUpStack(s, 7);
	printStack(*s);
	printStack(*s);

	removeAt(*s, 2);
	printStack(*s);

	cout << s->searchStack("d") << endl;
	cout << s->searchStack("s") << endl;
	

	delete s;
	system("pause");
}