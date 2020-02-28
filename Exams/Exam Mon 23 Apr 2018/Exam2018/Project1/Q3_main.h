#ifndef Q3_MAIN_H_
#define Q3_MAIN_H_

#include<iostream>
#include<string>
using namespace std;

int * generateData(int n);

int linearSearch(int * data, int N, int val);

void testLinearSearch(int N);
void quickSort(int * data, int first, int last);
void _quickSort(int * data, int first, int last);
int binarySearch(int * data, int first, int last, int val);
void testQuickSort_BinarySearch(int * data, int N, int val);
#endif // !Q3_MAIN_H_
