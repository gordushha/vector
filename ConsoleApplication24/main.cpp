#include "Vector.h"
#include "Matrix.h"
#include <iostream>
using namespace std;



int main()

{
  srand(time(NULL));
    /*Vector<double> v1(5);
    v1[2] = 42;
    std::cout << v1 << std::endl;
    Vector<double> v2(v1);
    std::cout << v2 << std::endl;
    Vector <double> v3;
     v1 + v2;
    cout << v1 << endl << " + " << endl << v2 << endl << " = " << endl << v3 << endl;
    v3 = v1 - v2;
    cout << v1 << endl << " - " << endl << v2 << endl << " = " << endl << v3 << endl;
    v3 = v1 * v2;
    cout << v1 << endl << "*" << endl << v2 << endl << " = " << endl << v3 << endl;
    
    v3.quicksort();


    Matrix <double> m1(2, 2);
    Matrix<double> m2(2, 2);
    Matrix<double> M;
    M = m1 * m2;
    cout << m1 << endl << " * " << endl << m2 << endl << " = " << endl << M << endl;
    M = m1 + m2;
    cout << m1 << endl << " + " << endl << m2 << endl << " = " << endl << M << endl;
    M = m1 * m2;
    cout << m1 << endl << " * " << endl << m2 << endl << " = " << endl << M << endl;*/

    int t = 10;

    for (int i = 1; i < 5; i++)
    {
        Vector<double> v1(t);
        v1.bubblesort();
        t = t * 10;
	}

    t = 10;
            cout << endl;

    for (int i = 1; i < 5; i++)
    {
        Vector<double> v1(t);
        v1.insertionsort();
        t = t * 10;
	}

    t = 10;
            cout << endl;

    for (int i = 1; i < 5; i++)
    {
        Vector<double> v1(t);
        v1.quicksort();
        t = t * 10;
	}

    for (int i = 1; i < 5; i++)
    {
      Matrix<int> m1(t,t);
      m1*m1;
      t = t * 10;
    }

    return 0;

 
  //catch (length_error& ab) { cout << ab.what() << endl;
}
