#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

template<typename T>
class reciprocal {
public:
	T operator()(T x) {
		if (x == (T)0) {
			return (T)0;
		}
		else {
			return (T)1 / x;
		}
	}
};
template<typename T>
void show_vector(vector<T> const &v) {
	cout << "Contents of v :" << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << " " << v[i];
	}
	cout << endl << endl;
}

void main() {
	vector<double> v;
	for (int i = 10; i <= 100; i += 10) {
		v.push_back((double)i);
	}
	show_vector(v);

	transform(v.begin(), v.end(), v.begin(), negate<double>());
	show_vector(v);

	transform(v.begin(), v.end(), v.begin(), reciprocal<double>());
	show_vector(v);

	system("pause");
}