#ifndef PERSON_H_
#define PERSON_H_
#include <string>
#include <iosfwd>

// Person is a class that represents a human being
class Person {
public:
	// Constructors
	// Parameterised
	Person(std::string first, std::string family, std::string ID, int birth)	{
		given_name = first;
		family_name = family; 
		ID_number = ID;
		birth_year = birth;
	}

	// Default or parameter-less
	Person() : given_name(""), family_name(""), ID_number(""),
		birth_year(1900) {}

	// Modifier Functions
	// Sets the given_name field
	void set_given_name(const std::string& given) { given_name = given; }
	// Sets the family_name field
	void set_family_name(const std::string& family) { family_name = family; }
	// Sets the ID number field
	void set_ID_number(const std::string& ID) { ID_number = ID; }
	// Sets the birth_year field
	void set_birth_year(int new_birth_year) { birth_year = new_birth_year; }

	// Accessor Functions
	// Gets the person's given name
	std::string get_given_name() const { return given_name; }
	// Gets the person's family name
	std::string get_family_name() const { return family_name; }
	// Gets the person's ID number
	std::string get_ID_number() const { return ID_number; }
	// Gets the person's year of birth
	int get_birth_year() const { return birth_year; }

	// Other Functions
	// Calculates a person's age at this year's birthday
	int age(int year) const;
	// Determines whether a person can vote
	// Return true if the person's age is >= the voting age
	bool can_vote(int year) const;
	// Determines whether a person is a senior citizen
	// Return true if person's age >= age at which a person is considered to be a senior citizen
	bool is_senior(int year) const;
	// Compares two Person objects for equality
	// Return true if the Person objects have the same ID number; false if they don't
	bool operator==(const Person& per) const;
	// Compares two Person objects for inequality
	// Return the negation of the equals operator
	bool operator!=(const Person& per) const;
	// Insert a Person object per information in ostream os, and output using <<  
	friend std::ostream& operator<<(std::ostream& os, const Person& per);

private:
	// Data Fields
	// The given name
	std::string given_name;
	// The family name
	std::string family_name;
	// The ID number
	std::string ID_number;
	// The birth year
	int birth_year;
	
	// Constants
	// The age at which a person can vote
	static const int VOTE_AGE = 18;
	// The age at which a person is considered a senior citizen
	static const int SENIOR_AGE = 65;
};
#endif
