#pragma once

#include <iostream>

class Point
{
public:
  Point();
  Point(const double& xCoord, const double& yCoord);
  Point(const std::string& nameInput, const double& xCoord, const double& yCoord);
  ~Point() = default;

  friend std::ostream& operator<<(std::ostream& out, const Point& p);
  friend std::istream& operator>>(std::istream& in, Point& p);

  double xget() const;
  double yget() const;
  std::string getPointName() const;

  Point& xset(const double& xCoord);
  Point& yset(const double& yCoord);
  Point& setPointName(const std::string& nameInput);
  Point& setPoint(const std::string& nameInput, const double& xCoord, const double& yCoord);

  double radiusVectorLen() const;

  Point operator+(const Point& other) const;
  Point operator-(const Point& other) const;
  Point operator*(const double& scalar) const;
  Point& operator=(const Point& other) = default;
  friend Point operator*(const double& scalar, const Point& p);

private:
  double x, y;
  std::string pointName;
};
