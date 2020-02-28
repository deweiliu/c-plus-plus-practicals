#include"TreeNode.h"
#include<iostream>
#include "test2.h"
using namespace std;

enum weekday
{
	Friday, Monday, Saturday, Sunday, Thursday, Tuesday, Wednesday
};
char*week[] = { "Friday", "Monday", "Saturday", "Sunday", "Thursday", "Tuesday", "Wednesday" };

template<typename T>
int  depth(TreeNode<T>* tree) {
	if (tree) {
		int left, right;
		return(left = depth(tree->left)) > (right = depth(tree->right)) ? (left + 1) : (right + 1);
	}
	return 0;
}

void test2() {
	TreeNode<int> tree(Sunday, nullptr, nullptr);

	for (int i = Friday; i <= Saturday; i++) {
		tree.insert(&tree, i);
	}
	for (int i = Thursday; i <= Wednesday; i++) {
		tree.insert(&tree, i);
	}

	cout << "The depth of this tree is " << depth(&tree) << endl;

}