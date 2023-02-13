#pragma once

#include <stdexcept>
#include <iostream>
#include <iomanip>

class Matrix
{
public:
  Matrix();
  Matrix(int nRows, int nCols);
  Matrix(int nRows, int nCols, const double* inputData);
  Matrix(const Matrix& inputMatrix);

  ~Matrix();

  bool operator==(const Matrix& rhs) const;
  bool operator!=(const Matrix& rhs) const;

  Matrix& operator=(const Matrix& matrix);

  Matrix operator+(const Matrix& rhs) const;
  Matrix& operator+=(const Matrix& rhs);

  Matrix operator-(const Matrix& rhs) const;
  Matrix& operator-=(const Matrix& rhs);

  Matrix operator*(const Matrix& rhs) const;
  Matrix operator*(const double& rhs) const;
  friend Matrix operator*(const double& lhs, const Matrix& rhs);

  Matrix& operator*=(const Matrix& rhs);
  Matrix& operator*=(const double& rhs);

  friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix);
  friend std::istream& operator>>(std::istream& in, Matrix& matrix);

  const double* operator[](int i) const;
  double* operator[](int i);


private:
  double* matrixData;
  int matrixNumRows, matrixNumCols, matrixNumElements;

};
