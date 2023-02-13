#include "polygon.h"
#include "segment.h"


Polygon::Polygon(const std::string& shapeNameInput, const std::vector<Point>& pointsInput) : Shape(shapeNameInput, true)
{
  points = pointsInput;
}

Polygon::Polygon(const Polygon& obj) : Shape(obj.getShapeName(), true)
{
  points = obj.points;
}

Polygon::Polygon(const std::string& shapeNameInput) : Shape(shapeNameInput, true)
{
}

Polygon::~Polygon()
{
  for (auto point: points)
  {
    point.~Point();
  }
}

Polygon& Polygon::operator+=(const Point& new_point)
{
  points.push_back(new_point);
  return *this;
}

Polygon& Polygon::operator=(const Polygon& obj)
{
  std::vector<Point> pointsNew;
  for (const auto& point: obj.points)
  {
    pointsNew.push_back(point);
  }
  points = pointsNew;
  setShapeName(obj.getShapeName());
  setPolygonInfo(obj.getIsPolygon());
  return *this;
}

void Polygon::displayInfo() const
{
  std::cout << "--------------" << std::endl;
  std::cout << "Shape name: " << getShapeName() << std::endl;
  std::cout << "Is shape a polygon: " << getIsPolygon() << std::endl;
  std::cout << "Area: " << area() << std::endl;
  std::cout << "Perimeter: " << perimeter() << std::endl;
  std::cout << "Points list: " << std::endl;
  for (const auto& point: points)
  {
    std::cout << point << std::endl;
  }
  std::cout << "--------------" << std::endl << std::endl;
}

double Polygon::area() const
{
  double polygonArea = 0.0;
  int numPoints = int(points.size());
  for (int i = 1; i < numPoints; ++i)
  {
    polygonArea += points[i - 1].xget() * points[i].yget() - points[i - 1].yget() * points[i].xget();
  }
  polygonArea += points[numPoints - 1].xget() * points[0].yget() - points[numPoints - 1].yget() * points[0].xget();
  return abs(polygonArea / 2);
}

double Polygon::perimeter() const
{
  double perimeter = 0.0;
  int numPoints = int(points.size());
  for (int i = 1; i < numPoints; ++i)
  {
    Segment tmp(points[i - 1], points[i]);
    perimeter += tmp.segmentLen();
  }
  Segment tmp(points[numPoints - 1], points[0]);
  perimeter += tmp.segmentLen();
  return perimeter;
}
