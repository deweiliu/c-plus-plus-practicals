#pragma once
#include<iostream>
using namespace std;
class CyclicQueue
{
public:
	CyclicQueue(int maxSize); // Constructor
	~CyclicQueue(); // Destructor
	void addAtEnd(int i); // Adds item to end of queue, if room
	int* removeFront(); // Returns pointer to front item, and removes it
	int* getAtFront(); // Returns pointer to front item, but doesn’t remove it
	bool isEmpty(); // Returns true if the queue is currently empty
	int size(); // Returns the number of items in the queue
private:
	int maxBufferSize; // Size of the array
	int* buffer; // The array (buffer) itself
	int first, last; // Positions of the first and last items in the buffer
	int numItems;	
	// Number of items currently in the buffer
};
