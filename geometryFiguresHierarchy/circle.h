#pragma once

#include "shape.h"

class Circle : public Shape
{
public:
  Circle();
  explicit Circle(const double& radius);
  double area() const;
  double perimeter() const;
  void displayInfo() const;

private:
  double r;
};
