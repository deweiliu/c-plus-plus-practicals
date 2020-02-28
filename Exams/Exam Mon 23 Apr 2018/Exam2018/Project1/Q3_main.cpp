#include "Q3_main.h"

template <class T>
void test3(const T& expected, const T &actual, const string& description = "") {
	cout << "Test for " << description << ": ";
	if (expected == actual) {
		cout << "Passed";
	}
	else {
		cout << "Failed";
	}
	cout << endl << "\tExpected: " << expected << "\tActual: " << actual << endl << endl;
}
void main3() {
	//(a)
	testLinearSearch(10);
	testLinearSearch(100);

	//(b)
	const int N = 5;
	int* data = generateData(N);
	_quickSort(data, 0, N - 1);
	test3(8, data[0], "(b)");
	test3(5, data[1], "(b)");
	test3(3, data[2], "(b)");
	test3(1, data[3], "(b)");
	test3(0, data[4], "(b)");
	delete[]	data;

	//(c)
	data = generateData(N);
	testQuickSort_BinarySearch(data, N, 9);
	delete[]	data;

	data = generateData(N);
	testQuickSort_BinarySearch(data, N, 0);
	delete[]	data;	

	data = generateData(N);
	testQuickSort_BinarySearch(data, N, 3);
	delete[]	data;

	data = generateData(N);
	testQuickSort_BinarySearch(data, N, 5);
	delete[]	data;	

	data = generateData(N);
	testQuickSort_BinarySearch(data, N, 8);
	delete[]	data;


	system("pause");
}
int* generateData(int n) {
	int* data = new int[n];
	data[0] = 5;
	data[1] = 1;
	data[2] = 8;
	data[3] = 0;
	data[4] = 3;
	return data;
}

int linearSearch(int* data, int N, int val)
{
	/* Code for the function */
	for (int i = 0; i < N; i++) {
		if (val == data[i]) {
			return i;
		}
	}
	return -1;
}

void testLinearSearch(int N)
{
	int* data = new int[N];
	for (int i = 0; i < N; i++) data[i] = rand() % 10;

	// Linear search for the first occurrence of val 
	int val = 3;
	cout << "The first occurrence of " << val << " is at "
		<< linearSearch(data, N, val) << endl;

	// Complexity of the search 
	cout << "The complexity of the search is " << "O(N)"
		<< endl;

	delete[] data;
}

// Partition 
void quickSort(int* data, int first, int last) {
	int i = first, j = last;
	int pivot = data[(first + last) / 2]; // Not necessarily the median 
	while (i <= j) {
		while (data[i] < pivot) i++;
		while (data[j] > pivot) j--;
		if (i <= j) { // Swap 
			int tmp = data[i];
			data[i] = data[j];
			data[j] = tmp;
			i++; j--;
		}
	}

	// Recursion: i is M 
	if (first < i - 1) quickSort(data, first, i - 1);
	if (i < last) quickSort(data, i, last);
}
//(b)
void _quickSort(int* data, int first, int last) {
	int i = first, j = last;
	int pivot = data[(first + last) / 2]; // Not necessarily the median 
	while (i <= j) {
		while (data[i] > pivot) i++;
		while (data[j] < pivot) j--;
		if (i <= j) { // Swap 
			int tmp = data[i];
			data[i] = data[j];
			data[j] = tmp;
			i++; j--;
		}
	}

	// Recursion: i is M 
	if (first < i - 1) _quickSort(data, first, i - 1);
	if (i < last) _quickSort(data, i, last);

	// The complexity of this algorithm is O(n * log(n)).
}

int binarySearch(int* data, int first, int last, int val)
{
	// Code for the function

	//No match value found
	if (first > last) {
		return -1;
	}
	int midle = (first + last) / 2;

	if (val < data[midle]) {
		return binarySearch(data, midle + 1, last, val);
	}
	if (val > data[midle]) {
		return binarySearch(data, first, midle - 1, val);
	}
	//val==data[midle]
	return midle;
}
void testQuickSort_BinarySearch(int* data, int N, int val)
{
	// Sort data into descending order
	_quickSort(data, 0, N - 1);
	// Search for the value val in the array
	cout << "Value " << val << " is found at "
		<< binarySearch(data, 0, N - 1, val) << endl;
	// Overall complexity
	cout << "The overall complexity of _quickSort + binarySearch"
		<< " is O(n * log(n))" << endl;
}
