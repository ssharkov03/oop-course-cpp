#include "shape.h"

Shape::Shape() : isPolygon(true)
{
}

Shape::Shape(const std::string& nameInput, const bool& isPolygonInput)
{
  shapeName = nameInput;
  isPolygon = isPolygonInput;
}


std::string Shape::getShapeName() const
{
  return shapeName;
}

bool Shape::getIsPolygon() const
{
  return isPolygon;
}

void Shape::setShapeName(const std::string& nameInput)
{
  shapeName = nameInput;
}

void Shape::setPolygonInfo(const bool& isPolygonInput)
{
  isPolygon = isPolygonInput;
}
