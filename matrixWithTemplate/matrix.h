#pragma once

#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <vector>

template <typename T>
class Matrix
{
public:
  Matrix();
  Matrix(int nRows, int nCols);
  Matrix(int nRows, int nCols, const std::vector<T>& inputData);
  Matrix(const Matrix<T>& inputMatrix);

  ~Matrix();

  bool operator==(const Matrix<T>& right) const;
  bool operator!=(const Matrix<T>& rhs) const;

  Matrix<T>& operator=(const Matrix<T>& matrix);

  Matrix<T> operator+(const Matrix<T>& rhs) const;
  Matrix<T>& operator+=(const Matrix<T>& rhs);

  Matrix<T> operator-(const Matrix<T>& rhs) const;
  Matrix<T>& operator-=(const Matrix<T>& rhs);

  Matrix<T> operator*(const Matrix<T>& rhs) const;
  Matrix<T> operator*(const T& rhs) const;
  template<typename U> friend Matrix<U> operator*(const U& lhs, const Matrix<U>& rhs);

  Matrix<T>& operator*=(const Matrix<T>& rhs);
  Matrix<T>& operator*=(const T& rhs);

  template<typename U> friend std::ostream& operator<<(std::ostream& out, const Matrix<U>& matrix);
  template<typename U> friend std::istream& operator>>(std::istream& in, Matrix<U>& matrix);

  const T* operator[](int i) const;
  T* operator[](int i);

  typename std::vector<T>::iterator begin() {return matrixData.begin(); }
  typename std::vector<T>::const_iterator cbegin() const { return matrixData.cbegin(); }
  typename std::vector<T>::iterator end() { return matrixData.end(); }
  typename std::vector<T>::const_iterator cend() const { return matrixData.cend(); }

private:
  std::vector<T> matrixData;
  int matrixNumRows, matrixNumCols, matrixNumElements;
};


template<typename T>
Matrix<T>::Matrix()
{
  matrixNumRows = 1;
  matrixNumCols = 1;
  matrixNumElements = 1;
  matrixData = std::vector<T>(1);

}

template<typename T>
Matrix<T>::Matrix(int nRows, int nCols)
{
  matrixNumRows = nRows;
  matrixNumCols = nCols;
  matrixNumElements = nRows * nCols;
  matrixData = std::vector<T>(matrixNumElements);
}

template<typename T>
Matrix<T>::Matrix(int nRows, int nCols, const std::vector<T>& inputData)
{
  matrixNumRows = nRows;
  matrixNumCols = nCols;
  matrixNumElements = nRows * nCols;
  matrixData = std::vector<T>(matrixNumElements);
  for (int i = 0; i < matrixNumElements; ++i)
  {
    matrixData[i] = inputData[i];
  }
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& inputMatrix)
{
  matrixNumRows = inputMatrix.matrixNumRows;
  matrixNumCols = inputMatrix.matrixNumCols;
  matrixNumElements = inputMatrix.matrixNumElements;
  matrixData = std::vector<T>(matrixNumElements);
  for (int i = 0; i < matrixNumElements; ++i)
  {
    matrixData[i] = inputMatrix.matrixData[i];
  }
}

template<typename T>
Matrix<T>::~Matrix()
{
  matrixData = std::vector<T>();
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs) const
{
  Matrix<T> res(*this);
  res += rhs;
  return res;
}

template<typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& rhs)
{
  for (int i = 0; i < matrixNumElements; ++i)
  {
    matrixData[i] += rhs.matrixData[i];
  }
  return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& rhs) const
{
  Matrix<T> res(*this);
  res -= rhs;
  return res;
}

template<typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& rhs)
{
  for (int i = 0; i < matrixNumElements; ++i)
  {
    matrixData[i] -= rhs.matrixData[i];
  }
  return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& rhs) const
{
  int l_numRows = matrixNumRows;
  int l_numCols = matrixNumCols;
  int r_numRows = rhs.matrixNumRows;
  int r_numCols = rhs.matrixNumCols;

  if (l_numCols == r_numRows)
  {
    Matrix<T> result(l_numRows, r_numCols);
    for (int leftRow = 0; leftRow < l_numRows; ++leftRow)
    {
      for (int rightCol = 0; rightCol < r_numCols; ++rightCol)
      {
        T elementResult(0);
        for (int leftCol = 0; leftCol < l_numCols; ++leftCol)
        {
          int leftLinearIdx = (leftRow * l_numCols) + leftCol;
          int rightLinearIdx = (leftCol * r_numCols) + rightCol; // leftCol = rightRow
          elementResult += (matrixData[leftLinearIdx] * rhs.matrixData[rightLinearIdx]);
        }
        int resultLinearIdx = (leftRow * r_numCols) + rightCol;
        result.matrixData[resultLinearIdx] = elementResult;
      }
    }
    return result;
  }
  throw std::out_of_range("Matrices are not compatible for multiplication.");
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const T& rhs) const
{
  Matrix<T> res(matrixNumRows, matrixNumCols);
  for (int i = 0; i < matrixNumElements; ++i)
  {
    res.matrixData[i] = matrixData[i] * rhs;
  }
  return res;
}

template<typename T>
Matrix<T> operator*(const T& lhs, const Matrix<T>& rhs)
{
  return rhs * lhs;
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& matrix)
{
  if (this == &matrix)
  {
    return *this;
  }
  if (matrixNumRows != matrix.matrixNumRows || matrixNumCols != matrix.matrixNumCols)
  {
    matrixNumRows = matrix.matrixNumRows;
    matrixNumCols = matrix.matrixNumCols;
    matrixNumElements = matrixNumRows * matrixNumCols;
    matrixData = std::vector<T>(matrixNumElements);
  }
  for (int i = 0; i < matrixNumElements; ++i)
  {
    matrixData[i] = matrix.matrixData[i];
  }
  return *this;
}

template<typename T>
Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& rhs)
{
  *this = *this * rhs;
  return *this;
}

template<typename T>
Matrix<T>& Matrix<T>::operator*=(const T& rhs)
{
  *this = *this * rhs;
  return *this;
}

template<typename T>
bool Matrix<T>::operator==(const Matrix<T>& right) const
{
  if ((matrixNumRows != right.matrixNumRows) || (matrixNumCols != right.matrixNumCols))
  {
    return false;
  }
  for (int i = 0; i < matrixNumElements; ++i)
  {
    if (matrixData[i] != right.matrixData[i])
    {
      return false;
    }
  }
  return true;
}

template<typename T>
bool Matrix<T>::operator!=(const Matrix<T>& rhs) const
{
  return !(*this == rhs);
}

template<typename T>
const T* Matrix<T>::operator[](int i) const
{
  return &matrixData[i * matrixNumCols];
}

template<typename T>
T* Matrix<T>::operator[](int i)
{
  return &matrixData[i * matrixNumCols];
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Matrix<T>& matrix)
{
  int nRows = matrix.matrixNumRows;
  int nCols = matrix.matrixNumCols;

  for (int row = 0; row < nRows; ++row)
  {
    for (int col = 0; col < nCols; ++col)
    {
      out << std::fixed << std::setprecision(2) << matrix[row][col] << " ";
    }
    out << std::endl;
  }
  return out;
}

template<typename T>
std::istream& operator>>(std::istream& in, Matrix<T>& m)
{
  std::cout << "Input size of matrix (number of rows, number of columns): ";
  in >> m.matrixNumRows >> m.matrixNumCols;
  m.matrixNumElements = m.matrixNumCols * m.matrixNumRows;
  m.matrixData = std::vector<T>(m.matrixNumElements);
  std::cout << "Input your matrix: " << std::endl;
  for (int i = 0; i < m.matrixNumElements; ++i)
  {
    in >> m.matrixData[i];
  }
  return in;
}
