#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

// 1. Testing if an array is sorted
bool isSorted(int* a, int N)
{
	for (int i = 0; i < N - 1; i++)
		if (a[i] > a[i + 1])
			return 0;
	return 1;
}

// 2. Insertion Sort algorithm & timing
void insertionSort(int* a, int N)
{
	for (int i = 1; i < N; i++) {
		// the item to be inserted in the sorted array b
		// i is one after the last item in the sorted array b
		int item = a[i];
		// search for insertion position p in b from beginning
		int p = 0;
		while (p < i && a[p] <= item) p++;
		// move everthing from position p up one place
		// starting at the end i, not from p!
		for (int j = i - 1; j >= p; j--) {
			a[j + 1] = a[j];
			Sleep(1);
		}
		// insert item at position p
		a[p] = item;
	}
}

// 3. Quick Sort algorithm & timing
void quickSort(int* a, int first, int last) 
{
	// partition
	int i = first, j = last;
	int pivot = a[(first + last) / 2];
	while (i <= j) {
		while (a[i] < pivot) {
			i++;
			Sleep(1);
		}
		while (a[j] > pivot) {
			j--;
			Sleep(1);
		}
		if (i <= j) {
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++; j--;
			Sleep(1);
		}
	}

	// recursion
	if (first < i - 1) quickSort(a, first, i - 1);
	if (i < last) quickSort(a, i, last);
}

int main()
{
	cout << "Array size example. N = ";
	int N = 0;
	cin >> N;

	// 1. Testing if an array is sorted
	int* a = new int[N];
	for (int i = 0; i < N; i++) a[i] = 3 * i + 1;		// an example of sorted array
	for (int i = 0; i < N; i++) cout << a[i] << " "; cout << endl;
	cout << "Array is sorted: " << isSorted(a, N) << endl << endl;

	for (int i = 0; i < N; i++) a[i] = rand() % 1000;	// an example of unsorted array
	for (int i = 0; i < N; i++) cout << a[i] << " "; cout << endl;
	cout << "Array is sorted: " << isSorted(a, N) << endl << endl;

	// backup unsorted a in b for comparing Insertion Sort & Quick Sort 
	int* b = new int[N]; 
	for (int i = 0; i < N; i++) b[i] = a[i];	

	// 2. Insertion Sort & timing
	cout << "Test insertion sort" << endl;
	clock_t begin = clock();
	insertionSort(a, N);
	clock_t end = clock();
	double elapsed = double(end - begin);
	cout << "Time taken to sort " << N << " values = " << elapsed << " ms = "
		<< elapsed / 1000.0 << " s" << endl;

	for (int i = 0; i < N; i++) cout << a[i] << " "; cout << endl;
	cout << "Array is sorted: " << isSorted(a, N) << endl << endl;

	// 3. Quick Sort & timing
	cout << "Test quick sort" << endl;
	begin = clock();
	quickSort(b, 0, N - 1);
	end = clock();
	elapsed = double(end - begin);
	cout << "Time taken to sort " << N << " values = " << elapsed << " ms = "
		<< elapsed / 1000.0 << " s" << endl;

	for (int i = 0; i < N; i++) cout << b[i] << " "; cout << endl;
	cout << "Array is sorted: " << isSorted(b, N) << endl << endl;

	delete[] a; delete[] b;
	return 0;
}
