#include <string>
#include <iostream>
#include <ctime>
#include "CyclicQueue.h"
#include "LinkedList.h"

using namespace std;

// Part 1
void testCyclicQueue1()
{
	CyclicQueue q(5);

	// getting a front item from an empty queue
	int* f = q.getAtFront();
	if(f) cout << "Front item = " << *f << endl;

	// adding to max queue capacity
	for (int i = 1; i <= 5; i++) q.addAtEnd(i);
	// adding to a full queue
	q.addAtEnd(100);
	
	// removing a front item
	f = q.removeAtFront();
	if (f) cout << "Front item = " << *f << endl;
	f = q.removeAtFront();
	if (f) cout << "Front item = " << *f << endl;

	// getting a front item
	f = q.getAtFront();
	if (f) cout << "Front item = " << *f << endl;
	f = q.getAtFront();
	if (f) cout << "Front item = " << *f << endl;
}

void testCyclicQueue2()
{
	CyclicQueue q(100);

	// Producer: adds 6 items (numbers 1..6)
	for (int i = 1; i <= 6; i++)
		q.addAtEnd(i);

	// Consumer: Prints and removes the front item
	if(!q.isEmpty())
		cout << "Front item = " << *q.removeAtFront() << endl;

	// Consumer: Prints and removes the front 2 items
	for (int i = 0; i < 2; i++)
		if (!q.isEmpty())
			cout << "Front item = " << *q.removeAtFront() << endl;

	// Producer: Adds 6 items (the integers 7..12)
	for (int i = 7; i <= 12; i++)
		q.addAtEnd(i);

	// Consumer: Prints and removes the front 3 items
	for (int i = 0; i < 3; i++)
		if (!q.isEmpty())
			cout << "Front item = " << *q.removeAtFront() << endl;

	// Consumer: Prints and removes the front item
	if (!q.isEmpty())
		cout << "Front item = " << *q.removeAtFront() << endl;

	// Producer: adds 6 items (numbers 13..18)
	for (int i = 13; i <= 18; i++)
		q.addAtEnd(i);

	// Consumer: Prints and removes the front 4 items
	for (int i = 0; i < 4; i++)
		if (!q.isEmpty())
			cout << "Front item = " << *q.removeAtFront() << endl;

	// Consumer: Flushes the queue - Prints and removes remaining items
	while (!q.isEmpty())
		cout << "Front item = " << *q.removeAtFront() << endl;
}

// Part 2
void testCountList()
{
	// an empty int list
	LinkedList<int> ilist;

	// set up the list with random numbers
	srand((unsigned)time(NULL));
	for (int n = 0; n < 100; n++) {
		int rand_num = rand() % 10;
		ilist.addAtEnd(rand_num);
	}

	// count occurrences of 0-19 in the stack
	for (int n = 0; n < 20; n++)
		cout << "Number of occurrences of " << n << " in the list is " << ilist.countList(n) << endl;
}

// Part 3
bool isLetter(char ch)
{
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

void testListOfWords()
{
	// a linked list of words
	LinkedList<string> words;

	// reading and set up the list terminated by a full stop
	char ch;
	string word = "";
	while (ch = cin.get()) {
		if (ch == '.') break;

		// word separator (e.g. space, ',' etc.) 
		if (!isLetter(ch)) {
			if (word != "") words.addAtEnd(word);
			word = "";
		}
		// a letter in word
		word = word + ch;
	}
}

// Part 4
void testOperatorOverload()
{
	// an empty char list
	LinkedList<char> clist;

	// add 10 chars one after another  
	for (int i = 0; i < 10; i++)
		clist + ('a' + i);

	// get chars at variable positions
	char *f = clist / 3;
	if(f)
		cout << "char at " << 3 << " is: " << *f << endl;
	f = clist / 7;
	if(f)
		cout << "char at " << 7 << " is: " << *f << endl;
}

int main()
{
	// Part 1: Cyclic Queue
	cout << "Part 1: First test of Cyclic Queue functions, with errors" << endl << endl;
	testCyclicQueue1();
	cout << endl;

	cout << "Part 1: Second test of Cyclic Queue - Producer and Consumer" << endl << endl;
	testCyclicQueue2();
	cout << endl << endl;

	// Part 2
	cout << "Part 2: Test countList function" << endl << endl;
	testCountList();

	// Part 3
	cout << "Part 3 Test creation of list of words" << endl << endl;
	testListOfWords();

	// Part 4
	cout << "Part 4: Test operator overloading" << endl << endl;
	testOperatorOverload();

	return 0;
}

