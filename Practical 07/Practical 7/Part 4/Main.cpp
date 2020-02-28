#include<iostream>
#include"LinkedList.h"
using namespace std;

void main() {
	// an empty char list
	LinkedList<char> clist;
	// add 10 chars one after another
	for (int i = 0; i < 10; i++)
		clist + ('a' + i);
	// get chars at variable positions
	char *f = clist / 3;
	if (f)
		cout << "char at " << 3 << " is: " << *f << endl;
	f = clist / 7;
	if (f)
		cout << "char at " << 7 << " is: " << *f << endl;
	system("pause");


}