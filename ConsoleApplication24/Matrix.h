#include <exception>
#include <iostream>
#include "Vector.h"
using namespace std;
using namespace std::chrono;
template<typename T>

class Matrix
{
public:
	Matrix() :M(0), n(0), m(0) {}

	Matrix(const Vector<T>& v1);
	Matrix(size_t size1, size_t size2, T** M_);

	~Matrix();

	Matrix operator +(const Matrix& other);
	Matrix operator *(const Matrix& other);

	Matrix(int size1, int size2);

	Matrix(const Matrix& other);


	Matrix operator -(const Matrix& other);


	Matrix& operator=(const Matrix& other);

	bool operator==(const Matrix<T>& other);

	const T* operator [](size_t i) const;

	T* operator [](size_t i);
	int GetN() const;
	int GetM() const;

private:
	T** M;
	size_t n;
	size_t m;
};

#include "Matrix_i.h"
