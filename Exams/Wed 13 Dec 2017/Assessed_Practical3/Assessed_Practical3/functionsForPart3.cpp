#include"functionsForPart3.h"

int evaluate(TreeNode<string> *tree, int X, int Y) {
	int result=INT_MIN;
	if (isOperator(tree->item)) {
		int left, right;
		switch (getOperator(tree->item)) {
		case '+':
			left = evaluate(tree->left, X, Y);
			right = evaluate(tree->right, X, Y);
			result = left + right;			
			break; 
		case '-':
			left = evaluate(tree->left, X, Y);
			right = evaluate(tree->right, X, Y);
			result = left - right;			
			break;
		case '*':left = evaluate(tree->left, X, Y); 
			right = evaluate(tree->right, X, Y);
			result = left * right;			
			break;
		case '/':left = evaluate(tree->left, X, Y); 
			right = evaluate(tree->right, X, Y);
			result = left / right;			
			break;
		default:cout << "A wrong operator in the tree node." << endl;
		}
	}
	else {
		if (isVariable(tree->item)) {
			result = getVariable(tree->item, X, Y);
		}
		else {
			if (isNumber(tree->item)) {
				result = stoi(tree->item);
			}
			else {
				cout << "Some thing goes wrong in the evaluate function." << endl;
				system("pause");
			}
		}
	}

	return result;

}

char getOperator(string a) {
	return a[0];
}
int getVariable(string a, int x, int y) {
	switch(a[0]) {
	case 'X': return x; break;
	case 'Y': return y; break;
	default: cout << "Some thing goes wrong in the getVariable function." << endl;
		return INT_MIN;
	}
}

bool isOperator(string a) {
	switch (a[0]) {
	case '+':case '-':case '*':case '/':
		return true; break;

	default: return false;
	}
}
bool isVariable(string a) {
	switch (a[0]) {
	case 'X':case 'Y': return true; break;
	default: return false;
	}
}
bool isNumber(string a) {
	if(isdigit(a[0])){
		return true;
	}
	else {
		return false;
	}
}