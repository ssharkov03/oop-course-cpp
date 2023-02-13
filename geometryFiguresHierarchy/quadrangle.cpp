#include "quadrangle.h"

Quadrangle::Quadrangle() : Polygon("quadrangle")
{
}

Quadrangle::Quadrangle(const std::vector<Point>& pointsInput) : Polygon("quadrangle", pointsInput)
{
  if (pointsInput.size() != 4){
    throw std::length_error("Points vector must be the size of 4.");
  }
}
