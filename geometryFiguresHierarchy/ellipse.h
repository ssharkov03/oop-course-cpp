#pragma once

#include "shape.h"

class Ellipse : public Shape
{
public:
  Ellipse();
  Ellipse(const double& aInput, const double& bInput);
  double area() const override;
  double perimeter() const;
  void displayInfo() const;

private:
  double a, b;
};
