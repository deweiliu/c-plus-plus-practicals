#ifndef FUNCTIONSFORPART3_H
#define FUNCTIONSFORPART3_H
#include<iostream>
#include<string>
#include"TreeNode.h"
using namespace std;

int evaluate(TreeNode<string> *tree, int X, int Y);

char getOperator(string a);

int getVariable(string a, int x, int y);

bool isOperator(string a);

bool isVariable(string a);

bool isNumber(string a);

#endif
