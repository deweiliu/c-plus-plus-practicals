#include"CyclicQueue.h"
CyclicQueue::CyclicQueue(int maxSize) {
	maxBufferSize = maxSize;
	first = 0;
	last = maxBufferSize - 1;
	numItems = 0;
	buffer = new int[maxBufferSize];
}
CyclicQueue::~CyclicQueue() {
	delete[] buffer;
}
void CyclicQueue::addAtEnd(int i) {
	if (numItems < maxBufferSize) {
		last = (last + 1) % maxBufferSize;
		buffer[last] = i;
		numItems++;
	}
	else {
		//Report error.
		cout << "The queue is full." << endl;
	}
}
int* CyclicQueue::removeFront() {
	int * temp = NULL;
	if (numItems > 0) {
		numItems--;
		temp = &buffer[first];
		first = (first + 1) % maxBufferSize;
	}
	return temp;
}
int* CyclicQueue::getAtFront() {
	int * temp = NULL;
	if (numItems > 0) {
		temp = &buffer[first];
	}
	return temp;
}
bool CyclicQueue::isEmpty() {
	return(numItems == 0) ? true : false;
}
int  CyclicQueue::size() {
	return numItems;
}
