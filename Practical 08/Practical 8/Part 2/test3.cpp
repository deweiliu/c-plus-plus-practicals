#include<iostream>
using namespace std;

#include"TreeNode.h"
#include"test3.h"
int sigma(TreeNode<int>* tree) {
	if (!tree) {
		return 0;
	}
	else {
		return tree->item + sigma(tree->left) + sigma(tree->right);
	}
}

void test3() {
	TreeNode<int> tree(5, nullptr, nullptr);
	for (int i = 0; i < 10; i++) {
		tree.insert(&tree, i);
	}
	cout << "The sum of this tree is " << sigma(&tree) << endl;
}