#include <iostream>
#include "Part_1.h"
#include "Person.h"

using namespace std;

int* getPtrToFive() {
	int *x = new int;
	*x = 5;
	return x;
}

// 7
int main()
{
	int *p = 0;
	for (int i = 0; i < 3; i++) {
		p = getPtrToFive();
		cout << *p << endl;
		// ADD THE FOLLOWING LINE TO FIX THE MEMORY LEAK
		delete p;
	}

	return 0;
}

// 6
int main6()
{
	// (a)
	Person p1("Jack", "Smith", "12345", 1990);
	cout << p1.get_ID_number() << endl;

	// (b)
	Person* p2 = new Person;
	p2->set_family_name("Jack");
	cout << p2->get_family_name() << endl;
	delete p2;

	// (c) 
	Person* p3 = new Person[10];
	cout << p3[9].get_birth_year() << endl;
	delete[] p3;

	return 0;
}

void fill_and_sum_array(int* array, int& sum, int array_len, int i0)
{
	if (array == NULL || array_len <= 0) {
		cout << "invalid array" << endl;
		return;
	}

	int* ptr = array;
	for (int i = 0; i < array_len; i++) {
		*ptr = i0 + i;
		ptr++;
	}

	/* missing instruction 1*/
	ptr = array; // THIS IS IT
	for (int i = 0; i < array_len; i++)
		cout << *ptr++ << endl;

	/* missing loop to calculate sum */
	// ANY CODE THAT WORKS, SUCH AS FOLLOWING
	sum = 0;
	for (int i = 0; i < array_len; i++)
		sum += array[i];
	/* OR
	sum = 0;
	ptr = array; 
	for (int i = 0; i < array_len; i++)
		sum += *ptr++;
	*/
}

// 5
int main5()
{
	int a[20];
	int s = -5;
	fill_and_sum_array(a, s, 20, 1);
	cout << "The sum of the elements is :" << s << endl;

	return 0;
}

// 4
int main4()
{
	// THE CORRECT CODE
	double a = 124.5;
	double* pa = &a;
	cout << *pa << endl;

	return 0;
}


// 3
int main3()
{
	double pi = 3.1415926;
	double* ptr = &pi;

	*ptr = *ptr * 3; // or pi = *ptr * 3;

	cout << *ptr << endl;

	return 0;
}

// 1, 2
int main2()
{
	cout << get_min(-2, -6, -9) << endl;

	double x = 10.2, y = 5.7, z = 8.0;
	cout << "x y z = " << x << " " << y << " " << z << endl;
	rotate(x, y, z);
	cout << "x y z = " << x << " " << y << " " << z << endl;

	// the C implementation
	rotate(&x, &y, &z);
	cout << "x y z = " << x << " " << y << " " << z << endl;
	
	return 0;
}
