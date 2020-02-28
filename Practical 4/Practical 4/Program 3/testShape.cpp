#include"Rectangle.h"
#include"Functions.h"
#include"Circle.h"
#include"Right Triangle.h"

void main() {
	Shape *s;
	shape_list();
	int option = get_option();
	switch (option) {
	case 1:s = new Rectangle; break;
	case 2:s = new Circle; break;
	case 3:s = new RightTriangle; break;
	default:exit(0);
	}
	s->read_shape_data();
	s->compute_area();
	s->compute_perimeter();
	s->print_result();
	system("pause");

}