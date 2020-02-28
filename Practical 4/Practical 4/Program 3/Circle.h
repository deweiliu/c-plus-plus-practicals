#pragma once
#include"Shape.h"
#include<math.h>
#define PI 3.14159265358
class Circle : public Shape
{
public:
	void compute_area() { area = PI*radius*radius; }
	void compute_perimeter() { perim = 2 * PI *radius; }
	void read_shape_data() {
		cout << "Enter radius of the circle : ";
		cin >> radius;
	}
private:
	int radius;
};

