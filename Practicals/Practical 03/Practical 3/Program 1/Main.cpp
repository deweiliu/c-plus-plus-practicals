#include<ostream>
#include<iostream>
#include "Person.h"
using namespace std;
void main() {
	Person* per1 = new Person("Dewei", "Liu", "001", 1996);
	cout << "Birth year : " << per1->get_birth_year() << endl;
	cout << "ID : " << per1->get_ID_number() << endl;
	cout << "This person : " << *per1;
	
	Person* per2=new Person();	
	per2->set_given_name("Abc");
	cout << "This person : " << *per2;

	Person* person_list = new Person[100];
	person_list[13].set_given_name("John");
	cout << "This 13th name is " << person_list[13].get_given_name() << endl;
	delete[]person_list;
	system("pause");
}