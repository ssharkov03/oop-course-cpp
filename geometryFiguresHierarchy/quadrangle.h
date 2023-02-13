#pragma once

#include "polygon.h"

class Quadrangle : public Polygon
{
public:

  Quadrangle();
  explicit Quadrangle(const std::vector<Point>& pointsInput);
};