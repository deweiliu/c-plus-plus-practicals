#pragma once
class Vecsim {
public:
	Vecsim(double* v1, double* v2, int v_len);

	double Euclidean();
	double Cosine();
private:
	double* vec1, *vec2;
	int vec_len;
};
