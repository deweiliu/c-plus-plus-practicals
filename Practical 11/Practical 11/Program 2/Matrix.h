#ifndef MATRIX_H_
#define MATRIX_H_
template<typename T>
class matrix {
public:

	//constructor & destructor
	matrix(int n_rows, int n_clos);
	~matrix();
	matrix(const matrix& o) :matrix(o.num_rows,o.num_cols){

		for (int i = 0; i < this->num_rows; i++) {
			for (int j = 0; j < this->num_cols; j++) {
				(*this)[i][j] = o.data[i][j];
			}
		}

	}


	//overload [] to return pointer to the i'th row of data
	T* operator[](int i);

	//overload + and * for matrices addition & multiplication
	matrix<T> operator+ (const matrix& a);
	matrix<T> operator*(const  matrix& a);

	int get_rows()const {
		return this->num_rows;
	}int get_cols() const {
		return this->num_cols;
	}

private:
	//matrix demensions & data
	int num_rows;
	int num_cols;
	T** data;
};



template<typename T>
inline matrix<T>::matrix(int n_rows, int n_clos)
{
	this->num_rows = n_rows;
	this->num_cols = n_clos;
	this->data = new T*[num_rows];
	for (int i = 0; i < num_cols; i++) {
		data[i] = new T[num_cols];
	}
}

template<typename T>
inline matrix<T>::~matrix()
{
	for (int i = 0; i < num_cols; i++) {
		delete[] data[i];
	}
	delete[] data;
}


template<typename T>
inline T * matrix<T>::operator[](int i)
{
	return data[i];
}

template<typename T>
inline matrix<T> matrix<T>::operator+ (const  matrix<T>& a)
{
	if (a.num_cols != this->num_cols || a.num_rows != this->num_rows) {
		throw std::exception("n");
	}

	matrix<T> temp(num_rows, num_cols);
	for (int i = 0; i < num_rows; i++) {
		for (int j = 0; j < num_cols; j++) {
			temp[i][j] = this->data[i][j] + a.data[i][j];
		}
	}

	return temp;
}

template<typename T>
inline matrix<T> matrix<T>::operator*(const matrix<T> & a)
{
	if (a.num_cols != this->num_rows || a.num_rows != this->num_cols) {
		throw std::exception("n");
	}


	matrix<T> temp(this->num_rows, a.get_cols());
	for (int i = 0; i < temp.get_rows(); i++) {
		for (int j = 0; j < temp.get_cols(); j++) {

			temp[i][j] = (T)0;
			for (int k = 0; k < this->num_cols; k++) {
				temp[i][j] += (this->data[i][k] * a.data[k][j]);
			}
		}
	}

	return temp;
}



#endif // !MATRIX_H_
