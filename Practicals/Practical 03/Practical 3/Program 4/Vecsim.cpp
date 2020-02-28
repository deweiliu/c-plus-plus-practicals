#include"Vecsim.h"
#include<math.h>
Vecsim::Vecsim(double* v1, double* v2, int v_len) {
	vec1 = v1;
	vec2 = v2;
	vec_len = v_len;
}


double Vecsim::Euclidean() {
	double euclidean=0;
	for (int j = 0; j < vec_len; j++) {
		euclidean += pow((vec1[j] - vec2[j]),2);
	}
	euclidean = sqrt(euclidean);
	return euclidean;
}