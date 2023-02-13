#pragma once

#include "point.h"

class Segment
{
public:
  Segment();
  Segment(const Point& A, const Point& B);
  Segment(const double& x1, const double& y1, const double& x2, const double& y2);
  ~Segment();

  double segmentLen() const;
  double getTangent() const;
  double getAngle() const;
  Point getPoint1() const;
  Point getPoint2() const;
  void displayInfo() const;

  friend std::ostream& operator<<(std::ostream& out, const Segment& s);

private:
  Point point1, point2;
};
