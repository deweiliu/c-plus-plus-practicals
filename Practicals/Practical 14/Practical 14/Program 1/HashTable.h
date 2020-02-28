#ifndef HASHTABLE_H
#define HASHTABLE_H
#include<math.h>
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

private:
	size_t		newTableSize();
	void reHash();
	// the hash table - each cell stores a pointer to an object of type X
	vector<X*> Table;
	// number of objects (pointers) stored in the table
	size_t num_x;
	// maximum load threshold of the table
	double LOAD_TH;
};

// constructor
template <class X>
HashTable<X>::HashTable(int table_size, double load_threshold)
	: LOAD_TH(load_threshold)
{

	// initialise each table cell to a NULL pointer
	for (int i = 0; i < table_size; i++)
		Table.push_back(NULL);
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
	if (load_factor > LOAD_TH) {
		reHash();
	}

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

template<class X>
inline size_t HashTable<X>::newTableSize()
{


	size_t size = Table.size() * 2 - 1;
	bool isPrime;
	do {
		size += 2;
		int sqr = sqrt((int)size);
		isPrime = true;
		for (int i = 2; i <= sqr; i++) {
			if (size%i == 0) {
				isPrime = false;
			}
		}
	} while (!isPrime);
	cout << "The old table size is " << Table.size() << "\t";

	cout << "The new table size is " << size << endl;
	return size;
}

template<class X>
inline void HashTable<X>::reHash()
{
	//Backup the old vector<X*> Table to a temporary vector<X*> oldTable
	vector<X*> old = this->Table;
	int old_num_x = num_x;

	//Obtain the new table size
	size_t size = newTableSize();

	//Delete the elements in the old Table
	Table.clear();
	num_x = 0;

	//Expand Table to the new size
	for (size_t i = 0; i < size; i++) {
		Table.push_back(NULL);
	}

	//Reinsert elements from oldTable into the expanded new Table
	for (int i = 0; num_x < old_num_x; i++) {
		if (X* a = old[i]) {
			this->insert(*a);
		}
	}

	//Delete the elements in the oldTable
	for (int i = 0; i < old.size(); i++)
	{
		if (old[i]) {
			delete old[i];
		}
	}






}

#endif
