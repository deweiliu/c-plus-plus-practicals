#ifndef STACK_H
#define STACK_H

class Stack {
public:
	// constructor
	Stack(int size);
	Stack(const Stack & a);
	// destructor
	~Stack();

	// public members(data and fuctions)
	void push(int i);
	int pop();

private:
	// private members (data and functions)
	int stck_size;
	int* stck;
	int tos;
};
#endif
