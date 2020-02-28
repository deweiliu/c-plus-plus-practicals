// Test_Person is an application that tests class Person
#include <iostream>
#include "Person.h"
using namespace std;

int main()
{
	Person p1("Adam", "Jones", "1234", 1963);
	p1.get_birth_year();
	cout << "p1: " << p1 << endl;

	Person p2;
	p2.set_family_name("Smith");
	cout << "p2: " << p2 << endl;

	Person* p3 = new Person("Joan", "O'Grady", "2345", 1972);
	cout << "p3: " << p3->get_ID_number() << endl;
	delete p3;

	Person* p4 = new Person;
	p4->set_birth_year(1953);
	cout << "p4: " << p4->get_birth_year() << endl;
	delete p4;
	
	Person* person_array = new Person[385];
	person_array[13].set_given_name("John");
	cout << "p13: " << person_array[13].get_given_name() << endl;
	delete[] person_array;

	return 0;
}
