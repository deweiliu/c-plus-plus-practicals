#include "PhoneDir.h"

// return the hash index of key - name
size_t PhoneDir::hash_index()
{
	size_t hash_index = 0;
	for (int i = 0; i < name.size(); i++) {
		char c = name[i];
		hash_index = 37 * hash_index + c;
	}
	return hash_index;
}
