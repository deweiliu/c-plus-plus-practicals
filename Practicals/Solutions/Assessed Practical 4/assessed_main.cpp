#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

// Part 1 (1): func
double func(int N)
{
	double total = 0.;
	for (int i = 0; i < N; i++)
		total += i * N;

	// Part 1 (1): (a)
	cout << "total = " << total << endl;
	// Part 1 (1): (b)
	cout << "The complexity of this loop structure is O(N)" << endl;

	return total;
}

// Part 1 (2): main
int main1()
{
	int M = 100;
	for (int N = 0; N < M; N++)
		cout << func(N) << endl;

	// Part 1 (2)
	cout << "The complexity of this loop structure is O(N squared)" << endl; // or O(N*N), O(N^2), ...
	// aletrnatively  - but the final answer must be O(N squared)
	cout << "The complexity of this loop structure is O(N * C(func(N))) = O(N squared)" << endl;

	return 0;
}

// Part 2: linearSearch_r
int linearSearch_r(int* a, int value, int N)
{
	//////////////////////////////////////////////////////////////////////////////////////////
	// The submitted solution should take advantage of the sorted array to speed up the search 
	//////////////////////////////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////////////
	// more efficient: search from the end for the last occurrence of value
	////////////////////////////////////////////////////////////////////////
	for (int i = N - 1; i >= 0; i--) {
		if (a[i] == value) return i;
		if (a[i] < value) return -1;	// (a[i] < value) stops the loop because a is sorted
	}
	return -1;

	// alternatively
	//int i = N - 1;
	//while (i >= 0 && a[i] > value)	// (a[i] <= value) stops the loop because a is sorted
	//	i--;
	//if (i >= 0 && a[i] == value)
	//	return i;
	//return -1;

	//////////////////////////////////////////////////////////////////////////
	//// less efficient: search from the beginning for the last occurrence of value
	//////////////////////////////////////////////////////////////////////////
	//int pos = -1;
	//for (int i = 0; i < N; i++) {
	//	if (a[i] == value) pos = i;
	//	if (a[i] > value) return pos;	// (a[i] > value) stops the loop because a is sorted
	//}
	//return -1;

	// alternatively
	//int i = 0;
	//while (i < N && a[i] <= value)	// (a[i] > value) stops the loop because a is sorted
	//	i++;
	//i--;
	//if (i >= 0 && a[i] == value)
	//	return i;
	//return -1;
}

// Part 2: main
int main2()
{
	// a sorted array for test
	int N = 32;
	int sortedArray[] = {14, 15, 20, 21, 24, 25, 30, 31, 34, 35, 40, 41, 44, 45, 50,
		51, 64, 65, 70, 71, 74, 75, 80, 84, 84, 84, 90, 91, 94, 95, 100, 101};

	// two tests to searach for value = -1 & 84; 84 is found at position 25
	// the tests can be implemenetd in variable ways; the following is one example
	int value;
	cout << "Value to search = ";
	cin >> value;

	int pos = linearSearch_r(sortedArray, value, N); 

	if (pos >= 0)
		cout << "Value " << value << " is found at position " << pos << endl;
	else
		cout << "Value " << value << " is not found." << endl;
	
	return 0;
}

// Part 3: bubbleSort
void bubbleSort(int* a, int N)
{
	bool sorted;
	do {
		sorted = true;
		for (int i = 0; i < N - 1; i++)
			if (a[i] > a[i + 1]) {	
				// out of order - swap a[i] and a[i+1]
				int temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
				sorted = false;
			}
	} while (sorted == false);
}

// Part 3: main
int main3()
{
	// read the array size
	cout << "Array size example. N = ";
	int N = 0;
	cin >> N;
	if (N <= 0) return 1;

	// create an array of N random integers
	int* array = new int[N];
	srand((unsigned)time(NULL));
	for (int n = 0; n < N; n++) array[n] = rand() % 10000;

	// your code to test the algorithm using the array goes here...
	bubbleSort(array, N);

	cout << "Sort array of " << N << " elements using Bubble Sort:" << endl;
	for (int i = 0; i < N; i++)
		cout << array[i] << " ";
	cout << endl;

	// must delete array
	delete[] array;

	return 0;
}

// Part 4: main
// the following is an example implementation of the required main
int main4()
{
	// initialise random number generator, may be ignored for this test
	srand((unsigned)time(NULL));	

	for (int N = 5000; N <= 30000; N += 5000) {
		// create an array of N random integers
		int* array = new int[N];
		for (int n = 0; n < N; n++) array[n] = rand() % 10000;	// can be rand() % 100, 1000, ...

		// time bubbleSort
		clock_t begin = clock();
		bubbleSort(array, N);
		clock_t end = clock();

		double elapsed = double(end - begin);

		// print result in required format
		cout << "Time taken (N is " << N << ") = " << elapsed << " ms = " << elapsed / 1000.0 << " s" << endl;

		// must delete array if is is created by using new as above
		delete[] array;
	}

	// print the required message about the complexity of bubbleSort
	// quadruple - time increases fourfold
	cout << "bubbleSort is O(N squared)." << endl;
	cout << "Evidence is that the time quadruples when we double N." << endl;

	return 0;
}

// Part 5: binary search
int binarySearch(vector<int>& v, int first, int last, int value)
{
	/* Error 2: should be first > last instead of first >= last */
	/* Or the value = v[N-1] won't be found in the array */
	if (first > last) return -1;

	int mid = (first + last) / 2;
	if (v[mid] == value)
		return mid;
	else if (value < v[mid])
		return binarySearch(v, first, mid - 1, value);
	else
		return binarySearch(v, mid + 1, last, value);
}

// Part 5: main
int main()
{
	// input data size 
	cout << "Data size examples. N = ";
	int N;
	cin >> N;
	if (N <= 0) {
		cout << "Invalid array size N = " << N << ". Return 1." << endl;
		return 1;
	}

	// create array v of N random numbers
	vector<int> v;
	srand((unsigned)time(NULL));
	for (int i = 0; i < N; i++) v.push_back(rand() % 1000);

	/* Error 1: the following line is missing */
	/* Array v must be sorted for binary search */
	sort(v.begin(), v.end());

	// binary search for value = v[N - 1]
	clock_t begin = clock();
	cout << "value found at " << binarySearch(v, 0, N - 1, v[N - 1]) << endl;
	clock_t end = clock();

	// time taken in ms and s
	double elapsed = double(end - begin);
	cout << "Time taken to search " << N << " values = " << elapsed << " ms = "
		<< elapsed / 1000.0 << " s" << endl << endl;

	return 0;
}
