#ifndef Q4_MAIN_H_
#define Q4_MAIN_H_
#include<iostream>
#include<string>
#include"Graph.h"
using namespace std;

void testGraph(char * fname);

size_t hash_index(string firstname, string surname, string student_no, size_t tableSize);

size_t hash_index_one_string(string firstname, size_t tableSize);

#endif // !Q4_MAIN_H_
