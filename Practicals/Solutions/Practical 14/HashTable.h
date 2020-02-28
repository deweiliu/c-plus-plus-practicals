#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
using std::vector;

// hash table storing class X objects using linear probing
template <class X>
class HashTable {
public:
	// constructor sets the hash table size & load threshold
	HashTable(int table_size, double load_threshold = 0.75);
	// destructor
	~HashTable();

	// search in the table for object a using its key and retrieve 
	// its value if found
	size_t find(X& a);	// size_t = unsigned int
	// insert new object a in the table, return true if done
	bool insert(X& a);

	// return table size
	size_t tableSize() { return Table.size();  }

private:
	// the hash table - each cell stores a pointer to an object of type X
	vector<X*> Table;
	// number of objects (pointers) stored in the table
	size_t num_x;
	// maximum load threshold of the table
	double LOAD_TH;

	///////////////////////////
	// Practical 14 extensions
	///////////////////////////
	// Program 1 : find a new table size
	size_t newTableSise();
	// Program 2 : perform rehashing
	void reHash();
};

// constructor
template <class X>
HashTable<X>::HashTable(int table_size, double load_threshold)
	: LOAD_TH(load_threshold)
{
	// initialise each table cell to a NULL pointer
	for (int i = 0; i < table_size; i++) Table.push_back(NULL);
	// initialise number of objects stored to 0
	num_x = 0;
}

// destructor - delete dynamic memories allocated to store objects, associated with  
// the pointers stored in the tabel cells 
template <class X>
HashTable<X>::~HashTable()
{
	for (int i = 0; i < Table.size(); i++)
		if (Table[i]) delete Table[i];
}

// search in the table for object a using its key and retrieve its value if found
template <class X>
size_t HashTable<X>::find(X& a)
{
	// calculate the hash index for the key of object a
	size_t index = a.hash_index() % Table.size();

	// search using linear probing 
	// to find index of matching key or the 1st empty slot
	while (Table[index] != NULL && Table[index]->get_key() != a.get_key())
		index = (index + 1) % Table.size();

	// retrieve matching value for object a if found
	if (Table[index] != NULL) a.set_value(Table[index]->get_value());

	return index;
}

// insert new object a in the table, return true if done
template <class X>
bool HashTable<X>::insert(X& a)
{
	// calculate the load factor of the table
	double load_factor = (double)num_x / (double)Table.size();
	// rehashing if load factor exceeds the threshold
	if (load_factor > LOAD_TH) reHash();

	// search object a in the able
	size_t index = find(a);
	// not found, create a new entry in the table
	if (Table[index] == NULL) {
		Table[index] = new X(a);	// allocate memory to store the new object
		num_x++;	// increase the number of objects stored by 1
		return 1;
	}

	// object already in table, do nothing
	return 0;
}

// Program 1 : find a new table size
template <class X>
size_t HashTable<X>::newTableSise()
{
	// current table size
	size_t size = Table.size();

	// initial new size - twice as big, an odd number
	size = 2 * size + 1;
	bool prime = false;
	do {
		prime = true;
		int m = sqrt(size);
		// for an odd number, only consider odd divisors up to m
		for (int i = 3; i <= m; i += 2)
			if (!(size % i)) {	// remainder=0, so size is divisable by i, so it is not a prime 
				size += 2;		// update size, only consider odd numbers
				prime = false;
				break;
			}
	} while (!prime);

	return size;
}

// Program 2 : perform rehashing
template <class X>
void HashTable<X>::reHash()
{
	// old table size
	size_t oldSize = Table.size();

	// backup old Table to temporary oldTable & delete old table entries
	vector<X*> oldTable(oldSize, NULL);
	for (int i = 0; i < oldSize; i++) {
		if (Table[i] != NULL) {
			oldTable[i] = new X(*Table[i]);
			delete Table[i];
			Table[i] = NULL;
		}
	}
	
	// obtain new table size
	size_t newSize = newTableSise();

	// extend Table to new table size
	Table.resize(newSize, NULL);
	num_x = 0;

	// reinsert old Table elements into new table & delete temporary space
	for (int i = 0; i < oldSize; i++)
		if (oldTable[i] != NULL) {
			insert(*oldTable[i]);
			delete oldTable[i];
		}
}
#endif
