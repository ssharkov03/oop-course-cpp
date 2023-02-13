#include "ellipse.h"
#include <cmath>
#define M_PI 3.14159265358979323846

Ellipse::Ellipse() : Shape("ellipse", false), a(0.0), b(0.0)
{
}

Ellipse::Ellipse(const double& aInput, const double& bInput) : Shape("ellipse", false), a(aInput), b(bInput)
{
}

double Ellipse::area() const
{
  return M_PI * a * b;
}

double Ellipse::perimeter() const
{
  return 2 * M_PI * sqrt((a * a + b * b) / 2);
}

void Ellipse::displayInfo() const
{
  std::cout << "--------------" << std::endl;
  std::cout << "Shape name: " << getShapeName() << std::endl;
  std::cout << "Is shape a polygon: " << getIsPolygon() << std::endl;
  std::cout << "a, b: " << a << " " << b << std::endl;
  std::cout << "Area: " << area() << std::endl;
  std::cout << "Perimeter: " << perimeter() << std::endl;
  std::cout << "--------------" << std::endl << std::endl;
}
