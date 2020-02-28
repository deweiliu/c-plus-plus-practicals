// Part 1
#include "CyclicQueue.h"
#include <iostream>

using namespace std;

CyclicQueue::CyclicQueue(int maxSize)
	: maxBufferSize(maxSize)
{
	if (maxSize <= 0) {
		cout << "Buffer size error: " << maxSize << endl;
		return;
	}
	buffer = new int[maxBufferSize];
	first = 0;
	last = maxBufferSize - 1;
	numItems = 0;
}

CyclicQueue::~CyclicQueue()
{
	delete[] buffer;
}

void CyclicQueue::addAtEnd(int item)
{
	if (numItems < maxBufferSize) // not full
	{
		last = (last + 1) % maxBufferSize;
		buffer[last] = item;
		numItems++;
	}
	else
		cout << "Buffer full. Cannot add item" << endl;
}

int* CyclicQueue::removeAtFront()
{
	if (numItems > 0) // not empty
	{
		int* ptr_item = &buffer[first];
		first = (first + 1) % maxBufferSize;
		numItems--;
		return ptr_item;
	}
	else
	{
		cout << "Cannot remove front of empty buffer" << endl;
		return NULL;
	}
}

int* CyclicQueue::getAtFront()
{
	if (numItems > 0) // not empty
		return &buffer[first];
	else
	{
		cout << "Cannot get front of empty buffer" << endl;
		return NULL;
	}
}

bool CyclicQueue::isEmpty()
{
	return numItems == 0;
}

int CyclicQueue::size()
{
	return numItems;
}
