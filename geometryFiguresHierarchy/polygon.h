#pragma once

#include <vector>
#include "point.h"
#include "shape.h"


class Polygon : public Shape
{
public:

  Polygon(const std::string& shapeNameInput, const std::vector<Point>& pointsInput);
  Polygon(const Polygon& obj);
  explicit Polygon(const std::string& shapeNameInput);
  ~Polygon();

  Polygon& operator+=(const Point& new_point);
  Polygon& operator=(const Polygon& obj);

  double area() const;
  double perimeter() const;

  void displayInfo() const;

private:
  std::vector<Point> points;
};
