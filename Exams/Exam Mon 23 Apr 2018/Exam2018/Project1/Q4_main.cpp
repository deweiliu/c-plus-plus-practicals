#include "Q4_main.h"

template <class T>
void test4(const T& expected, const T &actual, const string& description = "") {
	cout << "Test for " << description << ": ";
	if (expected == actual) {
		cout << "Passed";
	}
	else {
		cout << "Failed";
	}
	cout << endl << "\tExpected: " << expected << "\tActual: " << actual << endl << endl;
}
void main4() {
	testGraph("graph.txt");

	size_t tableSize = 99;
	size_t hash = hash_index("HelloFirstName", "HelloSurname", "HelloStudent", tableSize);
	cout << "Hash code is " << hash << endl;
	test4(true, hash < tableSize);

	system("pause");
}
void testGraph(char* fname)
{
	// Task 1: Create a Graph object, to represent the graph defined in
	// the given definition file of name fname
	Graph graph(fname);

	// Task 2: Write code to search the graph to locate the edge with the
	// highest weight (assuming all weights >= 0)
	int highest = 0;
	int source = 0;
	int dest = 0;
	for (int i = 0; i < graph.num_v; i++) {
		for (int j = i; j < graph.num_v; j++) {
			if (graph.edges[j][i] > highest) {
				highest = graph.edges[j][i];
				source = i;
				dest = j;
			}
		}
	}

	// Task 3: Write code to output the found highest-weight edge in the
	// format: “Source-vertex Destination-vertex Weight”
	cout << "Source-vertex Destination-vertex Weight" << endl;
	cout << source << "\t" << dest << "\t" << highest << "\n";
}

size_t hash_index(string firstname, string surname, string student_no, size_t tableSize) {
	size_t hash = 0;
	hash += hash_index_one_string(firstname, tableSize);
	hash += hash_index_one_string(surname, tableSize);
	hash += hash_index_one_string(student_no, tableSize);

	return hash%tableSize;

}
size_t hash_index_one_string(string theString, size_t tableSize) {
	size_t hash = 0;
	for (int i = 0; i < theString.length(); i++) {
		hash += ((int)(theString[theString.length() - i - 1] * pow(37, i))) % tableSize;
	}
	return (size_t)((int)hash %tableSize);
}