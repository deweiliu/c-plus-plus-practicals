#ifndef FIND_MAX_H
#define FIND_MAX_H

template <typename T>
int find_max(T* array, int array_len)
{
	if (array == 0 || array_len <= 0) {
		cout << "invalid array" << endl;
		exit(1);
	}

	T max_v = array[0];
	int max_i = 0;
	for (int i = 1; i < array_len; i++)
		if (array[i] >= max_v) {
			max_v = array[i];
			max_i = i;
		}

	return max_i;
}

#endif
