/*
Name : Dewei Liu
Student No. 40216004
*/

#include<iostream>
#include "Person.h"
#include "part_1.h"
using namespace std;

//Part 1
int main2() {
	cout << get_min(4, 9, 5) << endl;

	double x = 10.2, y = 5.7, z = 8.0;
	rotate(x, y, z);
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "z = " << z << endl;

	system("pause");
	return 0;
}

//Part 2
int main3() {
	double pi = 3.1415926;
	double* ptr = &pi;
	*ptr *= 3;
	cout << "pi = " << pi << endl;


	system("pause");
	return 0;
}
int main4() {
	double a = 124.5;
	double*pa = &a;
	cout << *pa << endl;
	system("pause");
	return 0;
}
void fill_and_sum_array(int*array, int &sum, int array_len, int i0) {
	if (array == NULL || array_len <= 0) {
		cout << "invalide array" << endl;
		return;
	}

	int*ptr = array;
	for (int i = 0; i < array_len; i++) {
		*ptr = i0 + i;
		ptr++;
	}

	/*missing instruction 1*/
	ptr = array;
	sum = 0;
	for (int i = 0; i < array_len; i++) {
		sum += *ptr;

		cout << *ptr++ << endl;

		/*missing loop to caluculate sum*/

	}

}
int main5() {
	int a[20];
	int s = -5;
	fill_and_sum_array(a, s, 20, 1);
	cout << "The sum of the elements is : " << s << endl;
	system("pause");
	return 0;
}

//Part 3
int main6() {
	//Question (a)
	Person per_a("Dewei", "Liu", "40216004", 1996);
	cout << "ID number : " << per_a.get_ID_number() << endl;

	//Question (b)
	Person* per_b = new Person;
	per_b->set_family_name("Jack");
	cout << "Family name : " << per_b->get_family_name() << endl;
	delete per_b;

	//Question (c)
	Person* per_c = new Person[10];
	cout << "Birth year : " << per_c->get_birth_year() << endl;
	delete[] per_c;

	system("pause");
	return 0;
}
int* getPtrToFive() {
	int *x = new int;
	*x = 5;
	return x;
}
int main() {
	int *p = 0;
	for (int i = 0; i < 3; i++) {
		p = getPtrToFive();
		cout << *p << endl;
		delete p;
	}

	system("pause");
	return 0;
}
