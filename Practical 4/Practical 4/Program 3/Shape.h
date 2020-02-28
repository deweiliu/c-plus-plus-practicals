#pragma once
#include<iostream>
using namespace std;
class Shape {
public:
	virtual void compute_area() = 0; // a pure virtual function
	virtual void compute_perimeter() = 0; // a pure virtual function
	virtual void read_shape_data() = 0; // a pure virtual function
	virtual void print_result() { // a virtual function
		cout << "The area is " << area << endl
			<< "The perimeter is " << perim << endl;
	}
protected: // protected access specifier
	double area, perim;
};
