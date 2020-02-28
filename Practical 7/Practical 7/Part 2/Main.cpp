#include<iostream>
#include"LinkedList.h"
#include<ctime>
#include<random>
using namespace std;
void main() {
	LinkedList<int> l;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 100; i++) {
		l.addAtEnd(rand()%10);
	}
	for (int i = 0; i < 20; i++) {
		cout << "There are "<<l.countList( i)<< " " << i << "s in the list.\n";
	}

	system("pause");

}