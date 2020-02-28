#pragma once
#include"Shape.h"
#include<math.h>
class RightTriangle : public Shape
{
public:
	void compute_area() { area = e1 * e2 / 2; }
	void compute_perimeter() { perim = e1 + e2 + sqrt(pow(e1, 2) + pow(e2, 2)); }
	void read_shape_data() {
		cout << "Enter length of one edge : ";
		cin >> e1;
		cout << "Enter length of another edge : ";
		cin >> e2;
	}
private:
	int e1, e2;
};
