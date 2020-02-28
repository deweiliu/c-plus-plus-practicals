#ifndef MYCLASS_H_
#define MYCLASS_H_
#include<iostream>

class myClass
{
private:
	int* data;		// Private data, a data array
	int dataLength;	// Private data, length of the data array

public:
	// Constructor, which allocates memory for the data array to 
	// the given length len, and sets all elements of the array to 
	// the given value val
	myClass(int len, int val);

	//Default constructor
	myClass();
	// Destructor
	~myClass();

	// Find and return the maximum number in the data array
	int max_number();

	// Overload operator >= for comparing two objects. 
	// Object y >= Object x if the average of the numbers in y¡¯s 
	// data array >= the average of the numbers in x¡¯s data array.
	bool operator>=(const myClass& x);
};

#endif // !MYCLASS_H_

