#include<vector>
#include<iostream>
#include<algorithm>
#include<time.h>
using namespace std;
int modulo2(int i) {
	return i % 2;
}
template <typename T>
void show_vector(vector<T> const &v) {
	cout << "Contents of v :"<<endl;
		for (int i = 0; i < v.size(); i++) {
		cout << " " << v[i];
	}
	cout << endl << endl;
}
void main() {
	vector<int> v(10);
	srand((unsigned)time(NULL));
	for (int i = 0; i < v.size(); i++) {
		v[i] = rand() % 100;
	}
	show_vector(v);

	sort(v.begin(), v.end());
	show_vector(v);

	reverse(v.begin(), v.end());
	show_vector(v);

	transform(v.begin(), v.end(), v.begin(), modulo2);
	show_vector(v);

	system("pause");
}