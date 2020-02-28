// Dewei Liu 40216004

#include <vector>			// at the top of your program
#include <algorithm>	// at the top of your program
#include<iostream>
#include<ctime>
using namespace std;

//Part 1
double func(int N) {
	double total = 0.;
	for (int i = 0; i < N; i++) {
		total += i * N;
	}
	cout << "Total = " << total << endl;
	cout << "The complexity of this loop structure is O(N)" << endl;
	return total;
}

void main1() {
	int M = 100;
	for (int N = 0; N < M; N++)
		cout << func(N) << endl;
	cout << "The complexity of this loop structure is O(N*M)" << endl;
	system("pause");
}

//Part 2
int linearSearch_r(int* a, int value, int N) {
	int position = 0;
	while ((position < N) && (a[position] <= value)) {
		position++;
	}
	if (position > 0 && a[position - 1] == value) {
		return position - 1;
	}
	return -1;
}

void main2() {
	// A sorted array for test
	int N = 32;
	int sortedArray[] = { 14, 15, 20, 21, 24, 25, 30, 31, 34, 35, 40, 41, 44, 45, 50,
	51, 64, 65, 70, 71, 74, 75, 80, 84, 84, 84, 90, 91, 94, 95, 100, 101 };
	int arrayLength = sizeof(sortedArray) / sizeof(int);
	int position, value;
	value = -1;
	if ((position = linearSearch_r(sortedArray, value, arrayLength)) == -1) {
		cout << "The value of " << value << " does not exist in this array." << endl;
	}
	else {
		cout << "The value of " << value << " exists in this array and its position is " << position << "." << endl;
	}

	value = 84;
	if ((position = linearSearch_r(sortedArray, value, arrayLength)) == -1) {
		cout << "The value of " << value << " does not exist in this array." << endl;
	}
	else {
		cout << "The value of " << value << " exists in this array and its position is " << position << "." << endl;
	}

	system("pause");
}

//Part 3
void bubbleSort(int* array, int n) {
	if (n > 0) {
		bool sorted;
		do {
			sorted = true;
			for (int i = 0; i < n - 1; i++) {
				if (array[i] > array[i + 1]) {
					int temp = array[i];
					array[i] = array[i + 1];
					array[i + 1] = temp;
					sorted = false;
				}
			}
		} while (sorted == false);
	}
}
void printArray(int*a, int N) {
	for (int i = 0; i < N; i++) {
		if (i % 5 == 0) {
			cout << endl;
		}
		printf_s("%6d", a[i]);

	}
	cout << endl;
}
int main3() {

	// read the array size
	cout << "Array size example. N = ";
	int N = 0;
	cin >> N;
	if (N <= 0) { return 1; }

	// create an array of N random integers
	int* array = new int[N];
	srand((unsigned)time(NULL));
	for (int n = 0; n < N; n++) { array[n] = rand() % 10000; }

	// your code to test the algorithm using array goes here...
	cout << endl << "Array before sorting:";
	printArray(array, N);

	bubbleSort(array, N);
	cout << endl << "Array after sorting:";
	printArray(array, N);

	system("pause");
	return 1;
}

//Part 4
void testBubbleSort(int N) {
	int* array = new int[N];
	srand((unsigned)time(NULL));
	for (int n = 0; n < N; n++) { array[n] = rand() % 10000; }

	clock_t begin = clock();
	// your code to be timed goes here...	
	bubbleSort(array, N);

	clock_t end = clock();

	double elapsed = double(end - begin);
	cout << "Time taken (N is " << N << ") = " << elapsed << " ms = " << elapsed / 1000.0 << " s" << endl;
}

void main4() {
	int min = 5000;
	int max = 30000;
	int steps = 5000;
	for (int n = min; n <= max; n += steps) {
		testBubbleSort(n);
	}
	cout << "bubbleSort is O(N squared)." << endl;
	cout << "Evidence is that when we double N the time doubles TWICE (I mean the time is previous time to the power of 4)." << endl;

	system("pause");

}

//Part 5
// Implement a binary search algorithm
int binarySearch(vector<int>& v, int first, int last, int value)
{
	//Mistake 2. The recursion stops if and only if the index of first > that of last, insted of >=
	if (first > last) return -1;

	int mid = (first + last) / 2;
	if (v[mid] == value)
		return mid;
	else if (value < v[mid])
		return binarySearch(v, first, mid - 1, value);
	else
		return binarySearch(v, mid + 1, last, value);
}

// Main function for testing
int main()
{
	// input data size 
	cout << "Data size examples. N = ";
	int N;
	cin >> N;
	if (N <= 0) {
		cout << "Invalid array size N = " << N << ". Return 1." << endl;
		system("pause");
		return 1;
	}

	// create array v of N random numbers
	vector<int> v;
	srand((unsigned)time(NULL));
	for (int i = 0; i < N; i++) {
		v.push_back(rand() % 1000);
	}

	//Mistake 1. The array passed to binary binarySearch should be sorted.
	sort(v.begin(), v.end());


	// binary search for value = v[N - 1]
	clock_t begin = clock();
	cout << "value found at " << binarySearch(v, 0, N - 1, v[N - 1]) << endl;
	clock_t end = clock();

	// time taken in ms and s
	double elapsed = double(end - begin);
	cout << "Time taken to search " << N << " values = " << elapsed << " ms = "
		<< elapsed / 1000.0 << " s" << endl << endl;
	system("pause");
	return 0;
}