// Implementation file for the class Person
#include "Person.h"
#include <ostream>
using std::ostream;

// Calculates a person's age at this year's birthday
int Person::age(int year) const {
	return year - birth_year;
}

// Determines whether a person can vote
bool Person::can_vote(int year) const {
	int the_age = age(year);
	return the_age >= VOTE_AGE;
}

// Determines whether a person is a senior citizen
bool Person::is_senior(int year) const {
	return age(year) >= SENIOR_AGE;
}

// Compares two Person objects for equality
bool Person::operator==(const Person& per) const {
	return ID_number == per.ID_number;
}

// Compares two Person objects for inequality
bool Person::operator!=(const Person& per) const {
	return !(*this == per);
}

// Insert a Person object per information in ostream os, and output using <<  
ostream& operator<<(ostream& os, const Person& per) {
	os << "Given name: " << per.given_name << '\t'
		<< "Family name: " << per.family_name << '\n'
		<< "ID number: " << per.ID_number << '\t'
		<< "Year of birth: " << per.birth_year << '\n';
	return os;
}


