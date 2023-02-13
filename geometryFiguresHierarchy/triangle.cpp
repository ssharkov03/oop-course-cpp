#include "triangle.h"

Triangle::Triangle() : Polygon("triangle")
{
}

Triangle::Triangle(const std::vector<Point>& pointsInput) : Polygon("triangle", pointsInput)
{
  if (pointsInput.size() != 3){
    throw std::length_error("Points vector must be the size of 3.");
  }
}
