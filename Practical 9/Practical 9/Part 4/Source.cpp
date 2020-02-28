#include "..\Part 1\Source.h"
#include<math.h>
#include<algorithm>
#include<ctime>
#include<Windows.h>
#include<iostream>
#include<vector>
using namespace std;
int binarySearch(vector<int> const & a, int first, int last, int key);
void main() {
	vector<int> a; srand((unsigned)time(NULL));
	int const n = INT_MAX/10;
	cout << "n = " << n << endl;
	clock_t start = clock();
	for (int i = 0; i < n; i++) {
		a.push_back(rand());
		if ((int)clock() % 1000 == 0) {
			cout << (int)((double)i / n * 100) << "% finished. push back" << endl;
		}
	}	clock_t end = clock(); cout << "elapsed time : " << end - start << endl;


	cout << "sort started." << endl;
	sort(a.begin(), a.end());

	//for (int i = 0; i < n; i++)
	//{
	//	//cout << a.at(i) << " ";
	//}
	cout << endl; int key = a[5000];

	cout << "binary search started." << endl;
	int position = binarySearch(a, 0, n - 1, key);

	if (position == -1) {
		cout << "NOT found." << endl;
	}
	else {
		cout << "binary search : a[" << position << "] = " << a[position] << endl;
	}

	system("pause");
}
int binarySearch(vector<int> const & a, int first, int last, int key) {

	if (first > last) {
		return -1;
	}
	if ((int)clock() % 1000 == 0) {
		cout << (int)((1 - log(last - first) / log(INT_MAX/10)) * 100) << "% finished." << endl;
	}
	int current = (first + last) / 2;

	if (a[current] == key) {
		return current;
	}

	if (a[current] < key) {
		return binarySearch(a, current + 1, last, key);
	}

	return binarySearch(a, first, current - 1, key);
}