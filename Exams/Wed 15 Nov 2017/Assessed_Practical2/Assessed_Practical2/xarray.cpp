#include"xArray.h"

xArray::xArray(int size)
	: size(size)
{
	data = new int[size];
}
xArray::~xArray()
{
	delete[] data;
}
xArray::xArray(const xArray &a) {
	this->size = a.size;
	this->data = new int[this->size];
	for (int i = 0; i < size; i++) {
		this->data[i] = a.data[i];
	}
}

bool xArray::operator>=(const xArray &b) {
	int sum_a, sum_b;
	sum_a = sum_b = 0;
	for (int i = 0; i < this->size; i++) {
		sum_a += this->data[i];
	}
	for (int i = 0; i < b.size; i++) {
		sum_a += b.data[i];
	}
	if (sum_a >= sum_b) {
		return true;
	}
	else {
		return false;
	}
}