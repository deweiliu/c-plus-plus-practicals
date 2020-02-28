#pragma once
class xArray {
public:
	xArray(int size);
	~xArray();

	xArray(const xArray & a);

	bool operator>=(const xArray & b);


	int size;
	int* data;
};
