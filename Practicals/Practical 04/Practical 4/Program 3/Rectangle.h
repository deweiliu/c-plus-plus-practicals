#pragma once
#include"Shape.h"
class Rectangle : public Shape
{
public:
	void compute_area() { area = e1 * e2; }
	void compute_perimeter() { perim = 2 * e1 + 2 * e2; }
	void read_shape_data() {
		cout << "Enter width of the rectangle : ";
		cin >> e1;
		cout << "Enter height of the rectangle : ";
		cin >> e2;
	}
private:
	int e1, e2;
};