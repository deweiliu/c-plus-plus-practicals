#include <iostream>
#include <windows.h>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

// 1. test Sleep(1)
void testTiming(int N)
{
	clock_t begin = clock();

	for (int i = 0; i < N; i++)
		Sleep(1); // pauses about 1 ms

	clock_t end = clock();

	double elapsed = double(end - begin);
	cout << "Time taken with N = " << N << " is " << elapsed << " ms = " 
		<< elapsed / 1000.0 << " s" << endl << endl;
}

// 2. find average - O(N)
double findAverage(vector<int>& v, int N)
{
	cout << "Finding average.  N = " << N << endl;

	clock_t begin = clock();

	int total = 0;
	for (int i = 0; i < N; i++) {
		total += v[i];
		Sleep(1);
	}
	double average = total / N;

	clock_t end = clock();

	double elapsed = double(end - begin);
	cout << "Time taken to calculate average of " << N << " values = " << elapsed << " ms = "
		<< elapsed / 1000.0 << " s" << endl;

	return average;
}

// 3. count above average - O(2N) ~ O(N)
int countAboveAverage(vector<int>& v, int N)
{
	cout << "Counting number above average.  N = " << N << endl;

	clock_t begin = clock();

	double average = findAverage(v, N);
	
	int count = 0;
	for (int i = 0; i < N; i++) {
		Sleep(1);
		if (v[i] > average) count++;
	}

	clock_t end = clock();

	double elapsed = double(end - begin);
	cout << "Time taken to count " << N << " values = " << elapsed << " ms = "
		<< elapsed / 1000.0 << " s" << endl;

	return count;
}

// 4. binary search - O(log_2 N)
int binarySearch(vector<int>& v, int first, int last, int value)
{
	// base case - not found
	if (first > last) return -1;

	Sleep(1);

	int mid = (first + last) / 2;
	if (v[mid] == value)
		return mid;
	else if(value < v[mid])
		return binarySearch(v, first, mid - 1, value);
	else 
		return binarySearch(v, mid + 1, last, value);
}

// 5. find the valu which is the furthest from any other value - O(N^2)
int findFurthest(vector<int>& v, int N)
{
	int* temp = new int[N];

	// find for each value the closest other value
	for (int i = 0; i < N; i++) {
		int thisVal = v[i];
		int minDistance = MAXINT;
		for (int j = 0; j < N; j++) {
			Sleep(1);
			if (j != i)
				if (abs(thisVal - v[j]) < minDistance)
					minDistance = abs(thisVal - v[j]);
		}
		temp[i] = minDistance;
	}

	// find the value with the furthest closest other value
	int maxDistance = temp[0];
	int furthest = v[0];
	for (int i = 1; i < N; i++)
		if (temp[i] > maxDistance) {
			Sleep(1);
			maxDistance = temp[i];
			furthest = v[i];
		}
	delete[] temp;

	return furthest;
}

// main function
int main()
{
	// input data size 
	cout << "Data size examples. N = ";
	int N;
	cin >> N;

	// 1. test Sleep(1)
	testTiming(N);

	// create array of N random numbers
	vector<int> array;
	srand((unsigned)time(NULL));
	for (int i = 0; i < N; i++) array.push_back(rand() % 100000);

	// 2. test find average - O(N)
	cout << "average = " << findAverage(array, N) << endl << endl;

	// 3. test count above average - O(2N) ~ O(N)
	cout << "count above average = " << countAboveAverage(array, N) << endl << endl;

	// 4. test binary search in a sorted array - O(log_2 N)
	sort(array.begin(), array.end());

	clock_t begin = clock();
	cout << "value found at " << binarySearch(array, 0, N - 1, array[0]) << endl;
	clock_t end = clock();

	double elapsed = double(end - begin);
	cout << "Time taken to search " << N << " values = " << elapsed << " ms = "
		<< elapsed / 1000.0 << " s" << endl << endl;

	// 5. test find most remote value in a unsorted array - O(N^2)
	vector<int> array2;
	srand((unsigned)time(NULL));
	for (int i = 0; i < N; i++) array2.push_back(rand() % 100000);

	begin = clock();
	cout << "furthest value = " << findFurthest(array2, N) << endl;
	end = clock();

	elapsed = double(end - begin);
	cout << "Time taken to search " << N << " values = " << elapsed << " ms = "
		<< elapsed / 1000.0 << " s" << endl << endl;

	return 0;
}