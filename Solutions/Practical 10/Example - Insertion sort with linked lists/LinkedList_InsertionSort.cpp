#include <iostream>
#include <ctime>
#include "LinkedList.h"

using namespace std;

// test main function
int main()
{
	cout << "Linked list length N = ";
	int N;
	cin >> N;
	if (N <= 0) return 1;

	// create a linked list of int & add N random numbers to the list
	srand((unsigned int)(time(NULL)));
	LinkedList<int> iList;
	for (int n = 0; n < N; n++) iList.addAtEnd(rand() % 100);

	// before sorting, print the list from the 1st to the last item
	iList.setAtStart();
	for (int n = 0; n < iList.size; n++)
		cout << *iList.getNext() << " ";
	cout << endl << endl;

	// insertion sort iList
	iList.insertionSort();

	// after sorting, print the list from the 1st to the last item
	iList.setAtStart();
	for (int n = 0; n < iList.size; n++)
		cout << *iList.getNext() << " ";
	cout << endl;

	return 0;
}
