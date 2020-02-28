#ifndef SAFE_ARRAY
#define SAFE_ARRAY

// templae class safe array
template <typename T>
class safe_array {
public:
	safe_array(int size);
	~safe_array();

	T &operator[](int i);
private:
	int size;
	T* data;
};

template <typename T>
safe_array<T>::safe_array(int size)
	: size(size)
{
	if (size > 0) data = new T[size];
	else {
		cout << "invalid array size" << size << endl;
		exit(1);
	}
}

template <typename T>
safe_array<T>::~safe_array()
{
	delete[] data;
}

template <typename T>
T& safe_array<T>::operator[](int i)
{
	if (i < 0 || i >= size) {
		cout << "index " << i << " is out-of-bounds." << endl;
		exit(1);
	}
	return data[i];
}

#endif
