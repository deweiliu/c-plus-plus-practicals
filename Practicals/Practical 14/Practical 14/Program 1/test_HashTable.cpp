#include <iostream>
#include <time.h>
#include "PhoneDir.h"
#include "HashTable.h"

using namespace std;

int main()
{
	// store phone records in hash table with size 11
	HashTable<PhoneDir> HTable(3);
	HTable.insert(PhoneDir("Tom", 123456));
	HTable.insert(PhoneDir("Sam", 346834));
	HTable.insert(PhoneDir("Pete", 347980));
	HTable.insert(PhoneDir("Jack", 328709));
	HTable.insert(PhoneDir("David", 335566));


	HTable.insert(PhoneDir("Tom1", 12345));
	HTable.insert(PhoneDir("Sam1", 34683)); 
	HTable.insert(PhoneDir("Pete1", 34798));
	HTable.insert(PhoneDir("Jack1", 32870));
	HTable.insert(PhoneDir("David1", 33556));

	// serach using name for phone number over the hash table
	char yn = 'y';
	do {
		cout << "Whose phone number are you looking for? ";
		string name; cin >> name;

		// form enquiry - unknown phone number set to the default -1
		PhoneDir enquiry(name);	
		
		// search to retrieve the phone number if found
		clock_t begin = clock();
		size_t index = HTable.find(enquiry);
		clock_t end = clock();
		double elapsed = double(end - begin);

		// output
		cout << "index = " << index << endl;
		cout << "name = " << enquiry.get_key() << endl;
		cout << "number = " << enquiry.get_value() << endl;
		cout << "time taken = " << elapsed << " ms" << endl << endl;

		cout << "Another (y/n)? "; cin >> yn;
	} while (yn == 'y');

	return 0;
}
