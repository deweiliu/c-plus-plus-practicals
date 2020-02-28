#include "Shape.h"

int main()
{
	// a base-class poniter
	Shape* shape_ptr = NULL;

	// take user's choice
	cout << "Enter R for rectangle\nEnter C for circle\nEnter T for right triangle\n";
	char fig_type;
	cin >> fig_type;

	// allocate a derived object of the selected shape
	switch (fig_type) {
		// rectangle
	case 'R':
		shape_ptr = new Rectangle;
		break;
		// circle
	case 'C':
		shape_ptr = new Circle;
		break;
		// right triangle
	case 'T':
		shape_ptr = new Rt_Triangle;
		break;
	default:
		cout << "unknown shape selected" << endl;
	}

	// calculate the selected shape with the common interface
	if (shape_ptr != NULL) {
		shape_ptr->read_shape_data();
		shape_ptr->compute_area();
		shape_ptr->compute_perimeter();
		shape_ptr->print_result();
		delete shape_ptr;
	}

	return 0;
}
