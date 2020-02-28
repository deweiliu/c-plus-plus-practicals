
#include "Source.h"

void main() {
	vector<int> a; srand((unsigned)time(NULL));
	int const n = 40;
			cout << "n = " << n << endl;

	for (int i = 0; i < n; i++) {
		a.push_back(rand() % 100); cout << a[i] << endl;		
	}
	clock_t start = clock();
	int position = furthestNumber(a, n);
	clock_t end = clock();
	cout << "Elapsed time : " << end - start << endl;
	cout << "The furthest number is a[" << position << "] = " << a[position] << endl;
	system("pause");
}
int furthestNumber(vector<int>const &a, int n) {
	cout << endl;
	vector<int> distance;

	for (int i = 0; i < n; i++) {
		int x = findDistance(a, i, n);

		distance.push_back(x); Sleep(1);
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		Sleep(1);
		if (distance[max] < distance[i]) {
			max = i;
		}
	}
	
	return max;
}

int findDistance(vector<int>const &a,int position, int n) {
	int min = INT_MAX; int distance;
	for (int i = 0; i < n; i++) {
		Sleep(1);
		if(i!=position){
		distance =abs(a[i] - a[position]);		
			if (min > distance) {
				min = distance;
			}
		}
	}
	return min;
	
}