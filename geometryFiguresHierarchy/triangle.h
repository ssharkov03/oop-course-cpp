#pragma once

#include "polygon.h"

class Triangle : public Polygon
{
public:

  Triangle();
  explicit Triangle(const std::vector<Point>& pointsInput);
};
