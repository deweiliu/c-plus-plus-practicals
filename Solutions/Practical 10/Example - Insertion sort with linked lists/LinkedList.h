#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "ListNode.h"

template <typename T>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void addAtFront(T item);
	void addAtEnd(T item);
	void addAt(int p, T i);

	T* removeAtFront();
	T* removeAtEnd();
	T* removeAt(int p);

	T* getAtFront();
	T* getAtEnd();
	T* getAt(int p);

	void setAtStart();
	void setAtEnd();

	T* getNext();
	T* getPrevious();

	int size;	// current number of items in the list

	void insertionSort(); // perform insertion sort on the list

private:
	ListNode<T> *first, *current, *last;	// pointers to the 1st, current & last node in the link
	ListNode<T>* findAt(int p);	// return pointer to the node at location p
	T temp_item;	// storage, for the item to return 
};

template <typename T>
LinkedList<T>::LinkedList()
{
	first = current = last = NULL;
	size = 0;
}

template <typename T>
ListNode<T>* LinkedList<T>::findAt(int p)
{
	if (p < 0 || p >= size) {
		cout << "List item does not exist at position " << p << endl;
		return NULL;
	}
	int n = 0;
	ListNode<T>* ptr = first;
	while (n < p && ptr != NULL) {
		ptr = ptr->next;
		n++;
	}
	if (ptr == NULL)
		cout << "List item does not exist at position " << p << endl;
	return ptr;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	ListNode<T>* l = first;
	while (l != NULL) {
		ListNode<T>* n = l->next;
		delete l;
		l = n;
	}
}

template <typename T>
void LinkedList<T>::addAtFront(T item)
{
	ListNode<T>* l = new ListNode<T>(item, NULL, first);
	if (first != NULL) first->previous = l;
	first = l;
	if (last == NULL)
		last = l;
	size += 1;
}

template <typename T>
void LinkedList<T>::addAtEnd(T item)
{
	if (size == 0)
		addAtFront(item);
	else {
		ListNode<T> *l = new ListNode<T>(item, last, NULL);
		last->next = l;
		last = l;
		size++;
	}
}

template <typename T>
void LinkedList<T>::addAt(int p, T i)
{
	if (p == 0)
		addAtFront(i);
	else if (p == size)
		addAtEnd(i);
	else {
		ListNode<T>* temp = findAt(p);
		if (temp != NULL) {
			ListNode<T>* l = new ListNode<T>(i, temp->previous, temp);
			temp->previous->next = l;
			temp->previous = l;
			size++;
		}
	}
}

template <typename T>
T* LinkedList<T>::removeAtFront()
{
	if (size == 0) {
		cout << "No item to be removed at front of list" << endl;
		return NULL;
	}
	temp_item = first->item;
	ListNode<T>* temp = first;
	if (first->next != NULL)
		first->next->previous = NULL;
	first = first->next;
	size--;
	if(size == 0) last = NULL;
	delete temp;
	return &temp_item;
}

template <typename T>
T* LinkedList<T>::removeAtEnd()
{
	if (size == 0) {
		cout << "No item to be removed at end of list" << endl;
		return NULL;
	}
	temp_item = last->item;
	ListNode<T>* temp = last;
	if (last->previous != NULL)
		last->previous->next = NULL;
	last = last->previous;
	size--;
	if (size == 0) first = NULL;
	delete temp;
	return &temp_item;
}

template <typename T>
T* LinkedList<T>::removeAt(int p)
{
	if (p < 0 || p >= size) {
		cout << "No item to be removed at list position " << p << endl;
		return NULL;
	}
	if (p == 0)
		return removeAtFront();
	if (p == size - 1)
		return removeAtEnd();
	// Otherwise...
	ListNode<T>* temp = findAt(p);
	temp_item = temp->item;
	temp->previous->next = temp->next;
	temp->next->previous = temp->previous;
	size--;
	delete temp;
	return &temp_item;
}

template <typename T>
T* LinkedList<T>::getAt(int p)
{
	if (p < 0 || p >= size)
	{
		cout << "No item at list position " << p << endl;
		return NULL;
	}
	if (p == 0)
		return getAtFront();
	if (p == size - 1)
		return getAtEnd();
	// Otherwise...
	ListNode<T>* temp = findAt(p);
	current = temp;
	return &current->item;
}

template <typename T>
T* LinkedList<T>::getAtFront()
{
	if (size > 0) {
		current = first;
		return &first->item;
	}
	return NULL;
}

template <typename T>
T* LinkedList<T>::getAtEnd()
{
	if (size > 0) {
		current = last;
		return &last->item;
	}
	return NULL;
}

template <typename T>
void LinkedList<T>::setAtStart()
{
	current = first;
}

template <typename T>
void LinkedList<T>::setAtEnd()
{
	current = last;
}

template <typename T>
T* LinkedList<T>::getNext()
{
	if (current != NULL) {
		ListNode<T> *temp = current;
		current = current->next;
		return &temp->item;
	}
	return NULL;
}

template <typename T>
T* LinkedList<T>::getPrevious()
{
	if (current != NULL) {
		ListNode<T> *temp = current;
		current = current->previous;
		return &temp->item;
	}
	return NULL;
}

// In the program we do not use addAt(int p, T i)/getAt(int p)/removeAt(int p) as 
// these have O(N squared) complexity, while the algorithm below has O(N) complexity 
template <typename T>
void LinkedList<T>::insertionSort()
{
	if (size <= 1) return;

	// pt1 points to the item to be insertion sorted
	// start from the 2nd item
	ListNode<T>* pt1 = first->next;
	while (pt1) {
		// take the item pointed to by pt1 for insertion sort
		ListNode<T>* temp = pt1;
		T temp_item = temp->item;
		// move pt1 forward one item
		pt1 = pt1->next;

		// take the item to be insertion sorted off the list
		if (temp == first) {
			if (first->next) first->next->previous = NULL;
			first = first->next;
		}
		else if (temp == last) {
			if (last->previous) last->previous->next = NULL;
			last = last->previous;
		}
		else {
			temp->previous->next = temp->next;
			temp->next->previous = temp->previous;
		}

		// find a new position pt2 for the item in sorted order  
		ListNode<T>* pt2 = first;
		while (pt2 && pt2->item < temp_item)
			pt2 = pt2->next;

		// insert the item before the item pointed to by pt2 
		if (pt2 == first) {
			temp->previous = NULL;
			temp->next = first;
			first->previous = temp;
			first = temp;
		}
		else if (pt2 == NULL) {
			temp->previous = last;
			temp->next = NULL;
			last->next = temp;
			last = temp;
		}
		else {
			temp->previous = pt2->previous;
			temp->next = pt2;
			pt2->previous->next = temp;
			pt2->previous = temp;
		}
	}
}

#endif
