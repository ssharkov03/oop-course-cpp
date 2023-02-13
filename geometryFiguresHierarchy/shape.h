#pragma once

#include <string>
#include <iostream>

class Shape
{
public:
  Shape();
  explicit Shape(const std::string& nameInput, const bool& isPolygonInput);

  std::string getShapeName() const;
  bool getIsPolygon() const;
  virtual double area() const {return 0;}

  void setShapeName(const std::string& nameInput);
  void setPolygonInfo(const bool& isPolygonInput);

private:
  std::string shapeName;
  bool isPolygon;
};
