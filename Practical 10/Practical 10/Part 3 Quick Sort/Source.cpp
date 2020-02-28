#include<iostream>
#include<ctime>
#include<random>
using namespace std;
#include<vector>
#include "Source.h"
void main() {
	int const N = 10;
	int b[N] = { 5, 8, 33, 16, 14, 56, 50, 5,12,44 };
	quickSort(b, 0, N - 1);
	for (int i = 0; i < N; i++) {
		cout << b[i] << " ";
	}system("pause");
}

void quickSort(int* a, int first, int last) {
	if (first >= last) {
		return;
	}
	int left = first, right = last;
	int pivot = a[(first + last) / 2];
	int temp;
	while (left <= right) {
		while (a[left] < pivot) {
			left++;
		}while (a[right] > pivot) {
			right--;
		}if (left <= right) {
			temp = a[left];
			a[left] = a[right];
			a[right] = temp;
			left++; right--;
		}
	}
	quickSort(a, first, right);
	quickSort(a, left, last);
}
