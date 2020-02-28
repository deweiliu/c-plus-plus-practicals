// Code fragments for use in Assessed Practical 4

/////////////////
/* Part 1      */
/////////////////

// Code for function double func(int N)
double total = 0.;
for (int i = 0; i < N; i++)
	total += i * N;
return total;

// Code for main
int M = 100;
for (int N = 0; N < M; N++)
	cout << func(N) << endl;

/////////////////
/* Part 2      */
/////////////////

// A sorted array for test
int N = 32;
int sortedArray[] = {14, 15, 20, 21, 24, 25, 30, 31, 34, 35, 40, 41, 44, 45, 50,
51, 64, 65, 70, 71, 74, 75, 80, 84, 84, 84, 90, 91, 94, 95, 100, 101};

/////////////////
/* Part 3      */
/////////////////
// Set up data for test

// read the array size
cout << "Array size example. N = ";
int N = 0;
cin >> N;
if (N <= 0) return 1;

// create an array of N random integers
int* array = new int[N];
srand((unsigned)time(NULL));
for (int n = 0; n < N; n++) array[n] = rand() % 10000;

// your code to test the algorithm using array goes here...

/////////////////
/* Part 4      */
/////////////////
// To time a piece of code, in milliseconds
// Here's the code for Windows PCs:

#include <ctime>  // at the top of your program

clock_t begin = clock();
// your code to be timed goes here...
clock_t end = clock();

double elapsed = double(end - begin);
cout << "Time taken = " << elapsed << " ms = " << elapsed / 1000.0 << " s" << endl;

// Note for Mac users:
// The timer function clock() measures microseconds (millionths), not milliseconds (thousandths)
// So on a Mac, to convert the time to milliseconds, replace the line above with:

double elapsed = double(end - begin) * 1000;

/////////////////
/* Part 5      */
/////////////////
// A solution to Q4 of Practical 9

#include <vector>			// at the top of your program
#include <algorithm>	// at the top of your program

// Implement a binary search algorithm
int binarySearch(vector<int>& v, int first, int last, int value)
{
	if (first >= last) return -1;

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
		return 1;
	}

	// create array v of N random numbers
	vector<int> v;
	srand((unsigned)time(NULL));
	for (int i = 0; i < N; i++) v.push_back(rand() % 1000);

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
