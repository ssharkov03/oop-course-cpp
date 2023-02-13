#include <cmath>
#include "point.h"

Point::Point() : x(0.0), y(0.0)
{
}

Point::Point(const double& xCoord, const double& yCoord)
{
  x = xCoord;
  y = yCoord;
  pointName = "";
}

Point::Point(const std::string& nameInput, const double& xCoord, const double& yCoord)
{
  x = xCoord;
  y = yCoord;
  pointName = nameInput;
}

std::ostream& operator<<(std::ostream& out, const Point& p)
{
  if (p.pointName.empty())
  {
    out << "(" << p.x << ", " << p.y << ")";
  }
  else
  {
    out << p.pointName << "(" << p.x << ", " << p.y << ")";
  }
  return out;
}

std::istream& operator>>(std::istream& in, Point& p)
{
  std::cout << "Input name of point, x and y: " << std::endl;
  in >> p.pointName >> p.x >> p.y;
  return in;
}

double Point::xget() const
{
  return x;
}

double Point::yget() const
{
  return y;
}

std::string Point::getPointName() const
{
  return pointName;
}


Point& Point::setPoint(const std::string& nameInput, const double& xCoord, const double& yCoord)
{
  pointName = nameInput;
  x = xCoord;
  y = yCoord;
  return *this;
}

Point& Point::setPointName(const std::string& nameInput)
{
  pointName = nameInput;
  return *this;
}

Point& Point::xset(const double& x_coord)
{
  x = x_coord;
  return *this;
}


Point& Point::yset(const double& y_coord)
{
  y = y_coord;
  return *this;
}

double Point::radiusVectorLen() const
{
  return sqrt(x * x + y * y);
}

Point Point::operator+(const Point& other) const
{
  return {x + other.x, y + other.y};
}

Point Point::operator-(const Point& other) const
{
  return {x - other.x, y - other.y};
}

Point Point::operator*(const double& scalar) const
{
  return {x * scalar, y * scalar};
}

Point operator*(const double& scalar, const Point& p)
{
  return p * scalar;
}
