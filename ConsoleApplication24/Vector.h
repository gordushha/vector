#pragma once
#include <exception>
#include <iostream>
#include <time.h>
#include <chrono> 
#include <random>
using namespace std;
using namespace std::chrono;

template<typename T>
class Vector
{
public:
	Vector();

	Vector(const size_t size);
	T& operator [](size_t index) const;

	Vector(const Vector& other);

	~Vector();

	Vector(int num, int a, int b);

	int GetN() const;
	bool operator==(const Vector& other);


	Vector& operator=(const Vector& other);

	Vector<T> operator+ (const Vector<T>& other);
	Vector<T> operator- (const Vector<T>& other);
	Vector<T> operator* (const Vector<T>& other);

	template <typename Z> friend std::ostream& operator<<(std::ostream& stream, const Vector<Z>& self);


	template <typename Z> friend std::istream& operator>>(std::istream& stream, Vector<Z>& self);

	void insertionsort();
	void quicksort();
	void bubblesort();

	int Find(T a);
	void FindAll(T a);


private:
	T* arr;
	size_t n;
	void qs(int first, int last);

};

#include "Vector_i.h"






