#include <exception>
#include <iostream>
#include "Vector.h"
using namespace std;
using namespace std::chrono;
template<typename T>

class Matrix
{
public:
  Matrix():M(0), n(0),m(0){}

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

template <typename T>
Matrix<T>::Matrix(const Vector<T>& v1)
{
  n = v1.GetN();
  m = 1;

  M = new T * [n];
  for (int i = 0; i < n; i++)
    M[i] = new T[m];
  for (int i = 0; i < n; i++)
    
      M[i][0] = v1[i];

}
template <typename T>
  Matrix<T>::Matrix(size_t size1, size_t size2, T** M_)
  {
    n = size1;
    m = size2;

    M = new T * [n];
    for (int i = 0; i < n; i++)
      M[i] = new T[m];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        M[i][j] = M_[i][j];
  }

  template <typename T>
  Matrix<T>::~Matrix()
  {

 
 
      for (int i = 0; i < n; i++)
        delete[] M[i];
      delete[] M;
     
      n = 0;
      m = 0;

  }

  template <typename T>
  Matrix<T> Matrix<T>::operator +(const Matrix& other)
  {
    if ((this->m != other.m) || (this->n != other.n))
      throw length_error("-1");
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < m; i++) {
        (*this).M[k][i] = (*this).M[k][i] + other.M[k][i];
      }
    }
    return *this;
  }

  template <typename T>
  Matrix<T>::Matrix(int size1, int size2)
  {
    n = size1;
    m = size2;
    /*
    M = new T * [n];
    for (int i = 0; i < n; i++)
      M[i] = new T[m];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        M[i][j] = rand() % 100;
        */
    M = new T*[size1];
    for (int i = 0; i < size1; i++)
    {
        M[i] = new T[size2];
        for (int j = 0; j < size2; j++)
            M[i][j] = 0;
    }
  }

  template <typename T>
  Matrix<T>::Matrix(const Matrix& other)
  {
    n = other.n;
    m = other.m;
    M = new T * [n];

    for (int i = 0; i < n; i++)
      M[i] = new T[m];

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        M[i][j] = other.M[i][j];
  }

  template <typename T>
   Matrix<T> Matrix<T>::operator -(const Matrix& other)
  {
    Matrix newmatrix;
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < m; i++) {
        newmatrix[k][i] = M[k][i] - other.M[k][i];
      }
    }
    return newmatrix;
  }

  template <typename T>
  Matrix<T> operator * (const Matrix<T>& x, const Vector<T>& y)
  {
    return x * Matrix<T>(y);

  }

  template <typename T>
  Matrix<T> operator * (const Vector<T>& x, const Matrix<T>& y)
  {
    return Matrix<T>(x) * y;

  }
  
  template <typename T>
  int Matrix<T>::GetM() const
  {
    return m;
  }

  template <typename T>
  int Matrix<T>::GetN() const
  {
    return n;
  }

  template <typename T>
  Matrix<T>& Matrix<T>::operator=(const Matrix& other)
  {
    if (this == &other)
      return *this;
    for (int i = 0; i < n; i++)
      delete[] M[i];
    delete[] M;
    this->n = other.n;
    this->m = other.m;
    M = new T * [n];
    for (int i = 0; i < n; i++)
      M[i] = new T[m];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        M[i][j] = other.M[i][j];
    return *this;
  }

  template <typename T>
  bool Matrix<T>::operator==(const Matrix<T>& other)
  {
    if (n == other.n && m == other.m)
    {

      for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
          if (M[i][j] != other.M[i][j])
            return false;
      return true;
    }
    else
      return false;
  }

  template <typename T>
 const  T* Matrix<T>::operator [](size_t i) const
  {
    if (i >= n)
      throw  std::runtime_error("wrong index");

    else return M[i];

  }

 template <typename T>
  T* Matrix<T>::operator [](size_t i)
 {
   if (i >= n)
     throw  std::runtime_error("wrong index");

   else return M[i];

 }
 template <typename T>
 std::ostream& operator<<(std::ostream& stream, const Matrix<T>& self)
 {

   for (size_t index = 0; index < self.GetN(); index++)
     for (size_t k = 0; k < self.GetM();k++)
     stream << self[index][k] << std::endl;
   return stream;
 }

 template <typename T>
 std::istream& operator>>(std::istream& stream,  Matrix<T>& self)
 {

   size_t size1 = 0;
   size_t size2 = 0;

   stream >> size1;
   stream >> size2;
   Matrix <T> v4(size1,size2);
   for (size_t index = 0; index < size1; index++)
     for (size_t k = 0; k < size2; k++)
     stream >> v4[index][k];
   self = v4;
   return stream;
 }

  
  template <typename T>
  Matrix<T> Matrix<T>::operator*(const Matrix<T>& other)
  {
    auto start = high_resolution_clock::now();
    if (this->m == other.n)
    {
      Matrix<T> result;
      result.n = this->n;
      result.m = other.m;
      result.M = new T * [result.n];
      for (int i = 0; i < result.n; i++)
        result.M[i] = new T[result.m];

      for (int i = 0; i < result.n; i++)
        for (int j = 0; j < result.m; j++)
        {
          result.M[i][j] = 0;
          for (int k = 0; k < this->m; k++)
          {
            result.M[i][j] = result.M[i][j] + (M[i][k] * other.M[k][j]);
          }
        }
      return result;
    }
    else
      throw length_error("-1");
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by multiplication: "
      << duration.count() << " microseconds" << endl;
  }
