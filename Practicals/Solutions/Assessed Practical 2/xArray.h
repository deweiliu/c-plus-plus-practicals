#ifndef XARRAY_H
#define XARRAY_H

class xArray {
public:
	xArray(int size);
	~xArray();

	// copy constructor
	xArray(const xArray& x);
	// overload >=
	bool operator>=(const xArray& x);

	int size;
	int* data;
};

#endif

