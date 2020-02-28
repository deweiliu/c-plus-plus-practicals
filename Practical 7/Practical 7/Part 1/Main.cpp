#include"CyclicQueue.h"
#include"MyFunctions.h"


void main() {
	CyclicQueue q(5);

	printItem(q.removeFront());

	addItems(q, 0, 5);

	cout << endl << endl;

	CyclicQueue p(18);

	//Producer: Adds 6 items (the integers 1..6)
	addItems(p, 1, 6);
	cout << endl;

	//Consumer: Prints and removes the front item
	printItem(p.removeFront());
	cout << endl;

	//Consumer: Prints and removes the front 2 items
	printItem(p.removeFront());
	printItem(p.removeFront());
	cout << endl;

	//Producer: Adds 6 items (the integers 7..12)	addItems(p, 7, 12);
	cout << endl;

	//Consumer: Prints and removes the front three items
	printItem(p.removeFront());
	printItem(p.removeFront());
	printItem(p.removeFront());
	cout << endl;

	//Consumer: Prints and removes the front item	printItem(p.removeFront());
	cout << endl;

	//Producer: Adds 6 items (the integers 13..18)
	addItems(p, 13, 18);
	cout << endl;

	//Consumer: Prints and removes the front four items
	printItem(p.removeFront());
	printItem(p.removeFront());
	printItem(p.removeFront());
	printItem(p.removeFront());
	cout << endl;

	//Consumer: Flushes the buffer – prints and removes all remaining items
	while (!p.isEmpty()) {
		printItem(p.removeFront());
	}	
	cout << endl;



	system("pause");
}