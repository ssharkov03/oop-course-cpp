#pragma once

#include <iostream>

class Complex
{
public:
  Complex();

  explicit Complex(const double& real);

  Complex(const double& real, const double& imaginary);

  Complex operator+(const Complex& rhs) const;

  Complex operator+(const double& rhs) const;

  Complex operator+=(const double& rhs) const;

  Complex operator+=(const Complex& rhs) const;

  friend Complex operator+(const double& lhs, const Complex& rhs);

  Complex operator-(const Complex& rhs) const;

  Complex operator-(const double& rhs) const;

  friend Complex operator-(const double& lhs, const Complex& rhs);

  Complex operator*(const Complex& rhs) const;

  Complex operator*(const double& rhs) const;

  friend Complex operator*(const double& lhs, const Complex& rhs);

  Complex operator/(const Complex& rhs) const;

  Complex operator/(const double& rhs) const;

  friend Complex operator/(const double& lhs, const Complex& rhs);

  bool operator==(const Complex& rhs) const;

  bool operator!=(const Complex& rhs) const;

  friend std::ostream& operator<<(std::ostream& out, const Complex& c);

  friend std::istream& operator>>(std::istream& in, Complex& c);

  void printExponentialForm() const;


private:

  double re;
  double im;
};
