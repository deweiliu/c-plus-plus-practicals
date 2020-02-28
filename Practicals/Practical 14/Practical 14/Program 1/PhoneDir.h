#ifndef PHONEDIR_H
#define PHONEDIR_H

#include <string>
using std::string;

// class of phone directory
// a phone record consists of a key (name) and a value (phone number)
class PhoneDir {
public:
	// constructor sets the key (name) and value (phone number) 
	// of a phone record using the given information
	// if phone number is not given, it is set to a default value -1
	PhoneDir(string name, int number = -1)
		: name(name), number(number) {};

	// return key & value
	string get_key() const { return name; }
	int get_value() const { return number; }

	// set the phone number with the given num
	void set_value(int num) { number = num; }

	// return the hash index of key - name
	size_t hash_index(); 

private:
	// a phone record
	string name;	// key
	int number;		// value
};

#endif
