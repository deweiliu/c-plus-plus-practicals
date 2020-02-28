#include <iostream>
#include "ins_rem.h"
using namespace std;

//Program 1
int main_1()
{
	int sample[10]; // this reserves 10 integer elements

	//load the array
	for (int t = 0; t < 10; t++)   //for loops are useful to process arrays
		sample[t] = t;

	//display the array
	for (int t = 0; t < 10; t++)
		cout << "This is sample [" << t << "]: " << sample[t] << endl;
	return 0;
}

int main_2()
{

	int sample[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	//display the array
	for (int t = 0; t < 10; t++)
		cout << "This is sample [" << t << "]: " << sample[t] << endl;
	// define a pointer to the start of the array using the array name
	int* p = sample;

	//load the array using pointer arithmetic
	for (int t = 0; t < 10; t++)   
		*p++ = t * t;

	//display the array
	p = sample; 
	for (int t = 0; t < 10; t++)
		cout << "This is sample [" << t << "]: " << *p++ << endl;

	return 0;
}

//Program 2
int main_3()
{
	int i = 27;
	int *i_ptr = &i; // declare a pointer and give it the value of the address of i
	cout << "value in i is " << i << endl;
	cout << "address of i is " << i_ptr << endl;
	cout << "value from dereferencing pointer is " << *i_ptr << endl;

	*i_ptr = 35;     // change the value in i through pointer
	cout << "value in i is " << i << endl;

	double* d_ptr = NULL; // declare a pointer and initialise it to a NULL pointer
	cout << "value in pointer is " << d_ptr << endl;
	*d_ptr = 0.25;   // error! NULL is not a valid memory address
					 // always test a pointer before use it, as below
	if (d_ptr != NULL) *d_ptr = 0.25; // or if(d_ptr != 0) or if(d_ptr)

	/*Demonstrators, this is the incorrect version that the students were asked to fix.
		Corrected version is below
	int x = 10;
	int* p = NULL;

	*p = x;
	cout << *p << endl;
	*/

	int x = 10;
	int *p = NULL;

	p = &x;
	cout << *p << endl;

	int* p2 = NULL;

	if (p2 == NULL) {
		int x = 10;
		p2 = &x;
	}
	// x falls out of scope (x is undefined)
	// p2 is now a dangling pointer
	*p2 = 3;

	return 0;
}

//Program 3
int count_occurences(int* x, int n, int t)
{
	int count = 0;
	for (int i = 0; i < n; i++)
		if (x[i] == t) count++;
	return count;
}

bool same_elements(int* a, int* b, int n)
{
	for (int i = 0; i < n; i++)
		if (count_occurences(a, n, a[i]) != count_occurences(b, n, a[i]))
			return false;
	return true;
}

int main_4()
{
	int arraya[8] = { 121, 144, 19, 161, 19, 144, 19, 11 };
	int arrayb[8] = { 11, 121, 144, 19, 161, 19, 144, 19 };

	if (same_elements(arraya, arrayb, 8))
		cout << "The arrays are the same." << endl;
	else
		cout << "The arrays are not the same." << endl;

	return 0;
}

//Program 4
int main()
{
	int len = 8;
	int* array = new int[len];
	for (int t = 0; t < len; t++) array[t] = t;

	// array before insertion
	for (int t = 0; t < len; t++) cout << array[t] << " ";
	cout << endl;

	// insert a value 40 at element position 3
	insert(array, len, 3, 40);

	// array after insertion
	for (int t = 0; t < len; t++) cout << array[t] << " ";
	cout << endl;

	// remove an element at index position 6 
	remove(array, len, 6);

	// array after remove
	for (int t = 0; t < len; t++) cout << array[t] << " ";
	cout << endl;
	
	delete[] array;

	return 0;
}

