#include "complexNumbers.h"
#include <cmath>

Complex::Complex() : re(0), im(0)
{
}

Complex::Complex(const double& real) : re(real), im(0)
{
}

Complex::Complex(const double& real, const double& imaginary) : re(real), im(imaginary)
{
}

Complex Complex::operator+(const Complex& rhs) const
{
  return {re + rhs.re, im + rhs.im};
}

Complex Complex::operator+(const double& rhs) const
{
  return {re + rhs, im};
}

Complex operator+(const double& lhs, const Complex& rhs)
{
  return {rhs.re + lhs, rhs.im};
}

Complex Complex::operator-(const Complex& rhs) const
{
  return {re - rhs.re, im - rhs.im};
}

Complex Complex::operator-(const double& rhs) const
{
  return {re - rhs, im};
}

Complex operator-(const double& lhs, const Complex& rhs)
{
  return {rhs.re - lhs, rhs.im};
}

Complex Complex::operator*(const Complex& rhs) const
{
  double realPart = re * rhs.re - im * rhs.im;
  double imaginaryPart = re * rhs.im + rhs.re * im;

  return {realPart, imaginaryPart};
}

Complex Complex::operator*(const double& rhs) const
{
  return {re * rhs, im * rhs};
}

Complex operator*(const double& lhs, const Complex& rhs)
{
  return {rhs.re * lhs, rhs.im * lhs};
}

Complex Complex::operator/(const Complex& rhs) const
{
  double rDivisor = rhs.re * rhs.re + rhs.im * rhs.im;
  double realPart = (re * rhs.re + im * rhs.im) / rDivisor;
  double imaginaryPart = (im * rhs.re - re * rhs.im) / rDivisor;
  return {realPart, imaginaryPart};
}

Complex Complex::operator/(const double& divisor) const
{
  return {re / divisor, im / divisor};
}

Complex operator/(const double& lhs, const Complex& rhs)
{
  auto lhs_complex = Complex(lhs);
  return lhs_complex / rhs;
}

bool Complex::operator==(const Complex& rhs) const
{
  return (re == rhs.re && im == rhs.im);
}

bool Complex::operator!=(const Complex& rhs) const
{
  return !(*this == rhs);
}

void Complex::printExponentialForm() const
{
  double phi = std::atan2(im, re);
  double r = std::sqrt(re * re + im * im);
  std::cout << "z = r * exp(i * phi) = " << r << " * exp(i * " << phi << ")" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Complex& z)
{
  out << "(" << z.re << ", " << z.im << ")";
  return out;
}

std::istream& operator>>(std::istream& in, Complex& c)
{
  std::cout << "Input real and imaginary part (sep=' '): ";
  in >> c.re >> c.im;
  return in;
}

Complex Complex::operator+=(const double& rhs) const
{
  return {re + rhs, im};
}

Complex Complex::operator+=(const Complex& rhs) const
{
  return {re + rhs.re, im + rhs.im};
}
