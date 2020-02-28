#include <iostream>
#include <time.h>
#include "PhoneDir.h"
#include "HashTable.h"

using namespace std;

int main()
{
	// store phone records in hash table with size 5
	HashTable<PhoneDir> HTable(5);
	HTable.insert(PhoneDir("Tom", 123456));
	HTable.insert(PhoneDir("John", 346834));
	HTable.insert(PhoneDir("Jack", 347980));
	HTable.insert(PhoneDir("Clare", 328709));
	HTable.insert(PhoneDir("Razel", 335566));
	
	// serach using name for phone number over the hash table
	char yn = 'y';
	do {
		cout << "Whose number are you looking for? ";
		string name; cin >> name;

		// form enquiry - unknown phone number set to the default -1
		PhoneDir enquiry(name);

		// search to retrieve the phone number if found
		clock_t begin = clock();
		size_t index = HTable.find(enquiry);
		clock_t end = clock();
		double elapsed = double(end - begin);

		// output
		cout << "table size = " << HTable.tableSize() << endl;
		cout << "index = " << index << endl;
		cout << "name = " << enquiry.get_key() << endl;
		cout << "number = " << enquiry.get_value() << endl;
		cout << "time taken = " << elapsed << " ms" << endl << endl;

		cout << "Another (y/n)? "; cin >> yn;
	} while (yn == 'y');

	return 0;
}
