#include "myClass.h"

myClass::myClass(int len, int val)
{
	this->dataLength = len;
	data = new int[this->dataLength];
	for (int i = 0; i < this->dataLength; i++) {
		data[i] = val;
	}
}

myClass::myClass() :myClass(0, 0)
{
}

myClass::~myClass()
{
	delete[] data;
}

int myClass::max_number()
{
	int max = INT_MIN;
	for (int i = 0; i < this->dataLength; i++) {
		if (max < data[i]) {
			max = data[i];
		}
	}
	return max;
}

bool myClass::operator>=(const myClass & x)
{
	double thisAverage = 0, xAverage = 0;
	for (int i = 0; i < this->dataLength; i++) {
		thisAverage += this->data[i];
	}
	thisAverage /= this->dataLength;

	for (int i = 0; i < x.dataLength; i++) {
		xAverage += x.data[i];
	}
	xAverage /= x.dataLength;

	return thisAverage >= xAverage;
}
