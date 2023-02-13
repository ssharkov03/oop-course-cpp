#include "circle.h"
# define M_PI 3.14159265358979323846

Circle::Circle(): Shape("circle", false), r(0.0)
{
}

Circle::Circle(const double& radius) : Shape("circle", false), r(radius)
{
}

void Circle::displayInfo() const
{
  std::cout << "--------------" << std::endl;
  std::cout << "Shape name: " << getShapeName() << std::endl;
  std::cout << "Is shape a polygon: " << getIsPolygon() << std::endl;
  std::cout << "Radius: " << r << std::endl;
  std::cout << "Area: " << area() << std::endl;
  std::cout << "Perimeter: " << perimeter() << std::endl;
  std::cout << "--------------" << std::endl << std::endl;
}

double Circle::area() const
{
  return M_PI * r * r;
}

double Circle::perimeter() const
{
  return 2 * M_PI * r;
}
