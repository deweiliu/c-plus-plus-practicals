#pragma once
#include<iostream>
using namespace std;
template <typename T>
class s_array {
private:
	int size;
	T* data;
public:
	
	T &operator[](int i);


	s_array(int sz);

	~s_array();

};

template <typename T>
T &s_array<T>::operator[](int i) {
	if (i < 0 || i >= size) {
		cout << "Out of bounds." << endl;
		
	}
	return data[i];
}
template <typename T>
s_array<T>::s_array(int sz) {
	size = sz;
	if (data = new T[size]) {
		;
	}
	else {
		cout << "Cannot create the class.";
		
	}
}
template <typename T>
s_array<T>::~s_array() {
	delete[]data;
}
