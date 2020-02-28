#pragma once


template <typename A>
int find_max(A* array, int length) {
	if (!array || length<1) {
		//The array does not exist.
		return -1;
	}
	int index = 0;
	int max = array[0];
	for (int i = 1; i < length; i++) {
		if (array[i] > max) {
			max = array[i];
			index = i;
		}
	}
	return index;
}
