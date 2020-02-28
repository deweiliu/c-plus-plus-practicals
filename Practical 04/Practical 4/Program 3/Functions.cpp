#include "Functions.h"
using namespace std;
void shape_list() {
	cout << "1. Rectangle" << endl;
	cout << "2. Circle" << endl;
	cout << "3. Right Triangle" << endl;

}

char  get_option() {
	char c;
	do {
		cout << "Choose shape : ";
		c = _getch();
	} while (!is_legal(c));
	cout << endl;
	return c - 48;
}

bool is_legal(char c) {
	switch (c) {
	case '1':case '2':case '3':return 1;
	default: return 0;
	}
}