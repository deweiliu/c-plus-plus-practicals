
#include "Q2_main.h"


template <class T>
void test2(const T& expected, const T &actual, const string& description = "") {
	cout << "Test for " << description << ": ";
	if (expected == actual) {
		cout << "Passed";
	}
	else {
		cout << "Failed";
	}
	cout << endl << "\tExpected: " << expected << "\tActual: " << actual << endl << endl;
}
void main2() {
	//(a)
	LinkedListOfInt(3);

	//(b)
	TreeNode<int>* tree = larger_BST();
	test2(41, tree->item, "(b)");

	//(c)
	printTreePreOrder(tree);
	test2(0, min_item(tree), "(c)");
	
	delete tree;
	system("pause");
}
void LinkedListOfInt(int N)
{
	// Declare a linked list of integers 
	LinkedList<int> iList;

	// Add N random integers into the list 
	for (int n = 0; n < N; n++) {
		int rand_num = rand() % 1000;
		/* (2) */
		iList.addAtEnd(rand_num);
	}

	// Print the numbers in the list, from the last to the first, 
	// without making changes to the list. 
	// Option 1: 
	for (int n = N - 1; n >= 0; n--)
		cout << *iList.getAt(n) << endl;

	// Option 2: 
	/* (3) */
	cout << "\nOption 2:\n";
	iList.setAtEnd();
	for (int n = N - 1; n >= 0; n--) {
		cout << *(iList.getPrevious()) << endl;
	}
	/* (4) */
	cout << "The complexity of Option 1 is O(N*N)." << endl;
	cout << "The complexity of Option 2 is O(N)." << endl;
}

TreeNode<int>* small_BST()
{
	TreeNode<int>* _5 = new TreeNode<int>(5);
	TreeNode<int>* _31 = new TreeNode<int>(31);
	TreeNode<int>* bst = new TreeNode<int>(17, _5, _31);
	bst->traverse();
	return bst;
}

TreeNode<int>* larger_BST() {

	TreeNode<int>* _0 = new TreeNode<int>(0);
	TreeNode<int>* _34 = new TreeNode<int>(34);
	TreeNode<int>* _24 = new TreeNode<int>(24, _0, _34);

	TreeNode<int>* _67 = new TreeNode<int>(67);
	TreeNode<int>* _78 = new TreeNode<int>(78);
	TreeNode<int>* _69 = new TreeNode<int>(69, _67, _78);

	TreeNode<int>* _41 = new TreeNode<int>(41, _24, _69);


	TreeNode<int>* bst = _41;
	bst->traverse();
	return bst;
}

//(c) (i)
void printTreePreOrder(TreeNode<int>* tree) {
	if (tree != nullptr) {
		cout << tree->item << endl;
		printTreePreOrder(tree->left);
		printTreePreOrder(tree->right);
	}
}
//(c) (2)
int min_item(TreeNode<int>* tree)
{
	if (tree == nullptr) {
		return INT_MAX;
	}
	else {
		return min(tree->item, min_item(tree->left), min_item(tree->right));
	}

}
int min(int a, int b, int c) {
	int minValue = a > b ? b : a;
	minValue = minValue > c ? c : minValue;
	return minValue;
}
