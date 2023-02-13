#include "segment.h"
#include <limits>
#include <cmath>

Segment::Segment() : point1(Point(0, 0)), point2(Point(0, 0))
{
}

Segment::Segment(const Point& A, const Point& B) : point1(A), point2(B)
{
}

Segment::Segment(const double& x1, const double& y1, const double& x2, const double& y2)
{
  point1 = Point(x1, y1);
  point2 = Point(x2, y2);
}

Segment::~Segment()
{
  point1.~Point();
  point2.~Point();
}

double Segment::segmentLen() const
{
  return (point1 - point2).radiusVectorLen();
}

double Segment::getTangent() const
{
  Point vec = point2 - point1;
  double x = vec.xget();
  double y = vec.yget();
  if (x == 0 && y > 0){
    return std::numeric_limits<double>::max();
  }
  if (x == 0 && y < 0){
    return std::numeric_limits<double>::min();
  }
  return y / x;
}

double Segment::getAngle() const
{
  Point vec = point2 - point1;
  return atan2(vec.yget(), vec.xget());
}

std::ostream& operator<<(std::ostream& out, const Segment& s)
{
  out << "(" << s.point1 << ", " << s.point2 << ")";
  return out;
}

Point Segment::getPoint1() const
{
  return point1;
}

Point Segment::getPoint2() const
{
  return point2;
}

void Segment::displayInfo() const
{
  std::cout << "--------------" << std::endl;
  std::cout << "Segment: " << *this << std::endl;
  std::cout << "Angle(in radians) with X axis: " << getAngle() << std::endl;
  std::cout << "Tangent of angle with X axis: " << getTangent() << std::endl;
  std::cout << "Segment length: " << segmentLen() << std::endl;
  std::cout << "--------------" << std::endl << std::endl;
}
