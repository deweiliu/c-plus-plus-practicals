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

// copy constructor
xArray::xArray(const xArray& x)
{
	size = x.size;
	data = new int[size];
	for (int n = 0; n < size; n++)
		data[n] = x.data[n];
}
// overload >=
bool xArray::operator>=(const xArray& x)
{
	int sum = 0;
	for (int n = 0; n < size; n++)
		sum += data[n];

	int x_sum = 0;
	for (int n = 0; n < x.size; n++)
		x_sum += x.data[n];

	return sum >= x_sum;
}
