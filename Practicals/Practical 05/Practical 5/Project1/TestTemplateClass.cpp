#include"s_array.h"
#include"Functions.h"
void main() {
	s_array<double> a(10);
	random_assign(a, 10);
	show_array(a, 10);
	cout << endl << endl;
	s_array<char> b(5);
	b[0] = 'a';
	b[10] = 'b';
	
	cout << b[0] << endl;
	system("pause");

}