#ifndef Q2_MAIN_H_
#define Q2_MAIN_H_
#include<iostream>
#include<string>
#include "LinkedList.h"
#include "ListNode.h"
#include "TreeNode.h"
using namespace std;

void printTreePreOrder(TreeNode<int>* tree);

int min_item(TreeNode<int>* tree);

int min(int a, int b, int c);

void LinkedListOfInt(int N);

TreeNode<int>* small_BST();
TreeNode<int>* larger_BST();
#endif // !Q2_MAIN_H_