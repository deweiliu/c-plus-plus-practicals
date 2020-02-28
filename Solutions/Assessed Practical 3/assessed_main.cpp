#include <iostream>
#include <ctime>
#include <string>
#include "LinkedStack.h"
#include "LinkedList.h"
#include "TreeNode.h"

using namespace std;

// Part 3 2)
int evaluate(TreeNode<string> *tree, int X, int Y)
{
	// base case
	if (tree == NULL) return 0;

	// tree->item is an operator
	if (tree->item == "+")
		return evaluate(tree->left, X, Y) + evaluate(tree->right, X, Y);
	else if (tree->item == "-")
		return evaluate(tree->left, X, Y) - evaluate(tree->right, X, Y);
	else if (tree->item == "*")
		return evaluate(tree->left, X, Y) * evaluate(tree->right, X, Y);

	// tree->item is a variable
	else if (tree->item == "X" || tree->item == "x") // lower case "x" is optional
		return X;
	else if (tree->item == "Y" || tree->item == "y") // lower case "y" is optional
		return Y;

	// tree->item is a constant int
	else return stoi(tree->item);
}

// Part 3
int main()
{
	// 1)
	TreeNode<string>* tree = new TreeNode<string>("+",
		new TreeNode<string>("X"),
		new TreeNode<string>("*",
			new TreeNode<string>("-",
				new TreeNode<string>("Y"),
				new TreeNode<string>("23")),
			new TreeNode<string>("6")));

	// OR
	/*
	TreeNode<string>* Y = new TreeNode<string>("Y");
	TreeNode<string>* two_three = new TreeNode<string>("23");
	TreeNode<string>* sub = new TreeNode<string>("-", Y, two_three);
	TreeNode<string>* six = new TreeNode<string>("6");
	TreeNode<string>* mul = new TreeNode<string>("*", sub, six);
	TreeNode<string>* X = new TreeNode<string>("X");
	TreeNode<string>* tree = new TreeNode<string>("+", X, mul);
	*/

	// 2)
	cout << evaluate(tree, 5, 3) << endl;

	// delete dynamically allocated tree
	delete tree;
	return 0;
}

// Part 2
int main2()
{
	// 1)
	// a linked list of characters
	LinkedList<char> sentence;	// (1) missing data type: char

	// reading and set up the list terminated by a full stop
	char ch;
	while (ch = cin.get()) {
		sentence.addAtEnd(ch);	// (2) missing statment 
		if (ch == '.') break;
	}

	// 2)
	// print the list
	sentence.printList();

	// 3)
	// search for an item in the list
	// assume the sentence is: "This is a test."
	cout << sentence.searchList('i') << endl; // 'i' is in the list
	cout << sentence.searchList('x') << endl; // 'x' is not in the list

	return 0;
}

// Part 1
int main1()
{
	// create LinkedStack object s
	LinkedStack<int> s;

	// set up the stack with random numbers
	srand((unsigned)time(NULL));
	for (int n = 0; n < 100; n++) {
		int rand_num = rand() % 10;
		s.push(rand_num);
	}

	// count occurrences of 0-19 in the stack (can be written in two separate loops for 0-9 and 10-19)
	for (int n = 0; n < 20; n++)
		cout << "Number of occurrences of " << n << " in the stack is " << s.countStack(n) << endl;

	return 0;
}