#include "matrix.h"


Matrix::Matrix()
{
  matrixNumRows = 1;
  matrixNumCols = 1;
  matrixNumElements = 1;
  matrixData = new double[matrixNumElements];
}


Matrix::Matrix(int nRows, int nCols)
{
  matrixNumRows = nRows;
  matrixNumCols = nCols;
  matrixNumElements = nRows * nCols;
  matrixData = new double[matrixNumElements];
}

Matrix::Matrix(int nRows, int nCols, const double* inputData)
{
  matrixNumRows = nRows;
  matrixNumCols = nCols;
  matrixNumElements = nRows * nCols;
  matrixData = new double[matrixNumElements];
  for (int i = 0; i < matrixNumElements; ++i)
  {
    matrixData[i] = inputData[i];
  }
}

Matrix::Matrix(const Matrix& inputMatrix)
{
  matrixNumRows = inputMatrix.matrixNumRows;
  matrixNumCols = inputMatrix.matrixNumCols;
  matrixNumElements = inputMatrix.matrixNumElements;
  matrixData = new double[matrixNumElements];
  for (int i = 0; i < matrixNumElements; ++i)
  {
    matrixData[i] = inputMatrix.matrixData[i];
  }
}


Matrix::~Matrix()
{
  delete[] matrixData;
}

Matrix Matrix::operator+(const Matrix& rhs) const
{
  Matrix res(*this);
  res += rhs;
  return res;
}


Matrix& Matrix::operator+=(const Matrix& rhs)
{
  for (int i = 0; i < matrixNumElements; ++i)
  {
    matrixData[i] += rhs.matrixData[i];
  }
  return *this;
}


Matrix Matrix::operator-(const Matrix& rhs) const
{
  Matrix res(*this);
  res -= rhs;
  return res;
}

Matrix& Matrix::operator-=(const Matrix& rhs)
{
  for (int i = 0; i < matrixNumElements; ++i)
  {
    matrixData[i] -= rhs.matrixData[i];
  }
  return *this;
}


Matrix Matrix::operator*(const Matrix& rhs) const
{
  int l_numRows = matrixNumRows;
  int l_numCols = matrixNumCols;
  int r_numRows = rhs.matrixNumRows;
  int r_numCols = rhs.matrixNumCols;

  if (l_numCols == r_numRows)
  {
    Matrix result(l_numRows, r_numCols);
    for (int leftRow = 0; leftRow < l_numRows; ++leftRow)
    {
      for (int rightCol = 0; rightCol < r_numCols; ++rightCol)
      {
        double elementResult = 0.0;
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

Matrix Matrix::operator*(const double& rhs) const
{
  Matrix res(matrixNumRows, matrixNumCols);
  for (int i = 0; i < matrixNumElements; ++i)
  {
    res.matrixData[i] = matrixData[i] * rhs;
  }
  return res;
}


Matrix operator*(const double& lhs, const Matrix& rhs)
{
  return rhs * lhs;
}

Matrix& Matrix::operator=(const Matrix& matrix)
{
  if (this == &matrix)
  {
    return *this;
  }
  if (matrixNumRows != matrix.matrixNumRows || matrixNumCols != matrix.matrixNumCols)
  {
    delete[] matrixData;
    matrixNumRows = matrix.matrixNumRows;
    matrixNumCols = matrix.matrixNumCols;
    matrixNumElements = matrixNumRows * matrixNumCols;
    matrixData = new double[matrixNumRows * matrixNumCols];
  }

  for (int i = 0; i < matrixNumElements; ++i)
  {
    matrixData[i] = matrix.matrixData[i];
  }
  return *this;
}


Matrix& Matrix::operator*=(const Matrix& rhs)
{
  *this = *this * rhs;
  return *this;
}

Matrix& Matrix::operator*=(const double& rhs)
{
  *this = *this * rhs;
  return *this;
}

bool Matrix::operator==(const Matrix& right) const
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


bool Matrix::operator!=(const Matrix& rhs) const
{
  return !(*this == rhs);
}


const double* Matrix::operator[](int i) const
{
  return &matrixData[i * matrixNumCols];
}

double* Matrix::operator[](int i)
{
  return &matrixData[i * matrixNumCols];
}

std::ostream& operator<<(std::ostream& out, const Matrix& matrix)
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

std::istream& operator>>(std::istream& in, Matrix& m)
{
  std::cout << "Input size of matrix (number of rows, number of columns): ";
  in >> m.matrixNumRows >> m.matrixNumCols;
  m.matrixNumElements = m.matrixNumCols * m.matrixNumRows;
  m.matrixData = new double[m.matrixNumElements];
  std::cout << "Input your matrix: " << std::endl;
  for (int i = 0; i < m.matrixNumElements; ++i)
  {
    in >> m.matrixData[i];
  }
  return in;
}
