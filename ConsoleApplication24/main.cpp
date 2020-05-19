#include "Vector.h"
#include "Matrix.h"
#include <iostream>
using namespace std;


int main()

{
	srand(time(NULL));
	Vector<double> v1(5);
	v1[2] = 42;
	Vector<double> v2(v1);
	Vector <double> v3;
	v1 + v2;


	Matrix <double> m1(2, 2);
	Matrix<double> m2(2, 2);
	Matrix<double> M;
	M = m1 + m2;

	int t = 10;

	for (int i = 1; i < 5; i++)
	{
		cout << "t = " << t << endl;
		Vector<double> v1(t);
		v1.bubblesort();
		t = t * 10;
	}

	t = 10;
	cout << endl;

	for (int i = 1; i < 5; i++)
	{
		cout << "t = " << t << endl;
		Vector<double> v1(t);
		v1.insertionsort();
		t = t * 10;
	}

	t = 10;
	cout << endl;

	for (int i = 1; i < 5; i++)
	{
		cout << "t = " << t << endl;
		Vector<double> v1(t);
		v1.quicksort();
		t = t * 10;
	}

	t = 10;
	cout << endl;

	for (int i = 1; i < 4; i++)
	{
		cout << "t = " << t << endl;
		Matrix<int> m1(t, t);
		m1 + m1;
		t = t * 10;
	}

	t = 1;
	cout << endl;

	for (int i = 1; i < 4; i++)
	{
		cout << "t = " << t << endl;
		Matrix<int> m1(t, t);
		m1* m1;
		t = t * 10;
	}

	return 0;
}