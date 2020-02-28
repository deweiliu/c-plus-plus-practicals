#include "MyFunctions.h"

void printItem(int *temp) {
	if (temp) {
		cout << *temp << endl;
	}
	else {
		cout << "The queue is empty.\n";
	}

}

void 	addItems(CyclicQueue &q, int a, int b) {
	for (int i = a; i <= b; i++) {
		q.addAtEnd(i);
	}

}
