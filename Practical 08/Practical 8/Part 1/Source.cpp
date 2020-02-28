#include<iostream>
#include"TreeNode.h"
using namespace std;

enum weekday
{
	Friday, Monday, Saturday, Sunday, Thursday, Tuesday, Wednesday
};
char*week[] = { "Friday", "Monday", "Saturday", "Sunday", "Thursday", "Tuesday", "Wednesday" };


void main() {
	TreeNode<int> tree(Sunday, NULL, NULL);


	tree.insert(&tree, Monday);
	tree.insert(&tree, Friday);
	tree.insert(&tree, Saturday);
	tree.insert(&tree, Tuesday);
	tree.insert(&tree, Thursday);
	tree.insert(&tree, Wednesday);


	for (int i = Friday; i <= Wednesday; i++) {
		cout << week[i] << " is ";
		if (!tree.searchTree(i)) {
			cout << "not ";
		}
		cout << "in this tree." << endl;
	}
	for (int i = Wednesday + 1; i <= 10; i++) {
		cout << i << " is ";
		if (!tree.searchTree(i)) {
			cout << "not ";
		}
		cout << "in this tree." << endl;
	}





	system("pause");
}