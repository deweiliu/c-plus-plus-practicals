#include<iostream>

#include"LinkedStack.h"
#include"StackNode.h"

#include"ListNode.h"
#include"LinkedList.h"

#include"TreeNode.h"

#include<random>
#include<ctime>
#include<string>

#include"functionsForPart3.h"

//rememer to delete after using a "new"
using namespace std;

//Part 1
void main1() {
	LinkedStack<int> s;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 100; i++) {
		s.push(rand() % 10);
	}

	int count = 0;
	for (int i = 0; i < 10; i++) {
		count += s.countStack(i);
		cout << "The occurrences of number " << i << " is " << s.countStack(i) << endl;
	}
	cout << "The total occurrences of number 0 - 9 is " << count << endl << endl;

	for (int i = 10; i < 20; i++) {
		cout << "The occurrences of number " << i << " is " << s.countStack(i) << endl;

	}
	system("pause");
}

//Part 2
void main2() {
	// a linked list of characters
	LinkedList<char> sentence;

	// reading and set up the list terminated by a full stop
	char ch;
	while (ch = cin.get()) {
		/* (2) */
		sentence.addAtEnd(ch);
		if (ch == '.') break;
	}
	sentence.printList();
	cout << endl;

	int position;
	for (ch = 'a'; ch < 'g'; ch++) {
		position = sentence.searchList(ch);
		if (position != -1) {
			cout << "The position of the first occurrence of '" << ch << "' is " << position << "." << endl;
		}
		else {
			cout << "'" << ch << "' is not in this list." << endl;
		}
	}

	system("pause");
}

//Part 3
void main() {

	TreeNode<string>* y = new TreeNode<string>("Y", nullptr, nullptr);
	TreeNode<string>* num23 = new TreeNode<string>("23", nullptr, nullptr);
	TreeNode<string>* minus = new TreeNode<string>("-", y, num23);
	TreeNode<string>* num6 = new TreeNode<string>("6", nullptr, nullptr);
	TreeNode<string>* multiple = new TreeNode<string>("*", minus, num6);
	TreeNode<string>* x = new TreeNode<string>("X", nullptr, nullptr);
	TreeNode<string>* add = new TreeNode<string>("+", x, multiple);
	delete add;
	
	TreeNode<string>* vx = new TreeNode<string>("X", nullptr, nullptr);
	TreeNode<string>* vy = new TreeNode<string>("Y", nullptr, nullptr);
	TreeNode<string>* add1 = new TreeNode<string>("+", vx, vy);
	TreeNode<string>* tree = add1;


	cout << evaluate(tree, 5, -3) << endl;
	delete tree;
	system("pause");
}
