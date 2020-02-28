#include <iostream>
#include <string>
#include "ArrayStack.h"
#include "StackNode.h"
#include "LinkedStack.h"

using namespace std;

// Functions (1)-(3) for ArrayStack objects
template<typename T>
void setUpStack(ArrayStack<T>* s, int num)
{
	cout << "Input " << num << " values: " << endl << endl;
	for (int n = 0; n < num; n++) {
		T item;
		cin >> item;
		s->push(item);
	}
	cout << endl;
}

template<typename T>
void printStack(ArrayStack<T>& s)
{
	ArrayStack<T> temp;
	while (!s.isEmpty()) {
		T* t = s.pop();
		cout << *t << endl;
		temp.push(*t);
	}
	cout << endl;

	while (!temp.isEmpty())
		s.push(*temp.pop());
}

template<typename T>
void removeAt(ArrayStack<T>& s, int p)
{
	ArrayStack<T> temp(s.size());
	if (p >= s.size()) {
		cout << "Can't remove item at position " << p << endl;
		return;
	}

	// Move the top items above position p to temp
	while (s.size() > p + 1)
		temp.push(*s.pop());
	// Remove item at p
	s.pop();
	// Move items in temp back to s
	while (!temp.isEmpty())
		s.push(*temp.pop());
}

// Functions (1)-(3) for LinkedStack objects
template<typename T>
void setUpStack(LinkedStack<T>* s, int num)
{
	cout << "Input " << num << " values: " << endl << endl;
	for (int n = 0; n < num; n++) {
		T item;
		cin >> item;
		s->push(item);
	}
	cout << endl;
}

//...

// Evaluating postfix expression inputted from cin
void evaluateExpression()
{
	cout << "Enter symbol # to end calculation" << endl << endl;

	ArrayStack<int> s;
	string in;

	// Take 1st input
	cin >> in;
	while (in != "#") {
		int i;
		try {
			i = stoi(in);	// stoi converts a character string to an integer. It throws an exception for invalid argument
		}
		catch (exception& e) {
			// Pop the top two items for postfix calculation
			int* x = s.pop();
			int* y = s.pop();
			if (!x || !y) {
				cout << e.what() << endl;
				break;
			}

			// Perform +, -, *, / operation
			if (in == "+") s.push(*x + *y);
			else if (in == "-") s.push(*y - *x);
			else if (in == "*") s.push(*x * *y);
			else if (in == "/" && *x != 0) s.push(*y / *x);
			// An unknown operator is encountered
			else {
				cout << e.what() << endl;
				break;
			}
			// Take next input
			cin >> in;
			continue;	// jump straight to the top of the innermost loop (here it's while)
		}
		// Push an int value onto stack
		s.push(i);

		// Take next input
		cin >> in;
	}

	int* result = s.pop();
	if (result) cout << "Reulst = " << *result << endl;
	cout << endl;
}

int main()
{
	// Part 1 (1)
	ArrayStack<string> s(10);
	setUpStack<string>(&s, 7);

	// Part 1 (2)
	cout << "Contents of stack" << endl;
	printStack(s);
	cout << "Check that contents of stack are unaltered" << endl;
	printStack(s);

	// Part 1 (3)
	cout << "Remove the bottom of the stack" << endl;
	removeAt(s, 1);
	printStack(s);

	// Part 2
	LinkedStack<string> s2;
	setUpStack(&s2, 7);

	int p = s2.searchStack("Tuesday");
	cout << "Search for Tuesday returns position " << p << endl;
	p = s2.searchStack("Wensday");
	cout << "Search for Wensday returns position " << p << endl;

	// Part 3
	evaluateExpression();

	return 0;
}
