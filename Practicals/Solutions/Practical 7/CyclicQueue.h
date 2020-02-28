// Part 1
#ifndef CYCLICQUEUE_H
#define CYCLICQUEUE_H

class CyclicQueue
{
public:
	CyclicQueue(int maxSize);
	~CyclicQueue();

	void addAtEnd(int item);
	int* removeAtFront();
	int* getAtFront();
	bool isEmpty();
	int size();

private:
	int maxBufferSize;
	int* buffer;
	int first, last, numItems;
};

#endif
