#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

// Because we are using generic types (templates), we must have the whole class in a single file
// instead of having separate .h and .cpp files

template <typename T>
class ArrayStack
{
public:
	ArrayStack(int size);
	ArrayStack();		// This will use a default size (100)
	~ArrayStack();

	void push(T val);
	T* pop();			// Removes and returns the pointer to the top item
	T* top();			// Returns the pointer to the top item; no change
	bool isEmpty();		// Returns true if the stack has no item
	int size();			// Returns the number of items in the stack

	// Part 2 extensions
	int searchStack(T item);

private:
	const static int defaultMaxSize = 100;  // When no size specified by the user
	int maxStackSize;	// User-defined maximum size
	T* stack;			// The array which holds the items
	int tos;			// Where the next item will go
};

template <typename T>
ArrayStack<T>::ArrayStack(int size)
{
	maxStackSize = size;
	stack = new T[maxStackSize];
	tos = 0;
}

template <typename T>
ArrayStack<T>::ArrayStack()
{
	maxStackSize = defaultMaxSize;
	stack = new T[maxStackSize];
	tos = 0;
}

template <typename T>
ArrayStack<T>::~ArrayStack()
{
	delete[] stack;
}

template <typename T>
void ArrayStack<T>::push(T item)
{
	if (tos == maxStackSize) {
		cout << "Stack Overflow" << endl;
		return;
	}
	stack[tos++] = item;
}

template <typename T>
T* ArrayStack<T>::pop()
{
	if (tos == 0) {
		cout << "Stack Underflow" << endl;
		return NULL;
	}
	return &stack[--tos];
}

template <typename T>
T* ArrayStack<T>::top()
{
	if (tos == 0) {
		cout << "Stack is empty" << endl;
		return NULL;
	}
	return &stack[tos - 1];
}

template <typename T>
bool ArrayStack<T>::isEmpty()
{
	return tos == 0;
}

template <typename T>
int ArrayStack<T>::size()
{
	return tos;
}

// Part 2 extensions
template <typename T>
int ArrayStack<T>::searchStack(T item)
{
	for (int p = tos - 1; p >= 0; p--)
		if (stack[p] == item)
			return p;

	return -1; // not found
}

#endif
