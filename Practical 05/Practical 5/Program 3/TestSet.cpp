#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
void main() {
	set<int> i;
	i.insert(3);
	i.insert(5);
	i.insert(7);
	i.insert(0);
	i.insert(9);
	i.insert(0);
	i.insert(3);


	cout << "This set contains: ";
	set<int>::iterator it;
	for (it = i.begin(); it != i.end(); it++) {
		cout << " " << *it;
	}
	cout << endl;
	int searchFor;
	cin >> searchFor;
	if (binary_search(i.begin(), i.end(), searchFor)) {
		cout <<  searchFor << " Found"  << endl;
	}
	else {
		cout << searchFor << " Not Found" << endl;

	}
	cout << *find(i.begin(), i.end(), searchFor);
	system("pause");
}