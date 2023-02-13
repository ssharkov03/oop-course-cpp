#include "segment.h"
#include "circle.h"
#include "ellipse.h"
#include "triangle.h"
#include "quadrangle.h"


int main()
{
  Point A("A", 0, 0);
  Point B("B", 1, 0);
  Point C("C", 1, 1);
  Point D("D", 0, 1);
  Point E("E", 5, 5);
  Point F("F", 10, 10);
  double radius = 6;
  double a = 2;
  double b = 1;

  Point N = E - 2*F;
  N.setPointName("N");
  std::cout << "Point: " << N << std::endl;

  Segment FN(F, N);
  FN.displayInfo();

  std::vector <Point> pointsForTriangle = {A, B, C};
  std::vector <Point> pointsForRectangle = {A, B, C, D};
  std::vector <Point> pointsForQuadrangle = {A, B, E, D};

  Triangle triang(pointsForTriangle);
  triang.displayInfo();

  Polygon rectang("rectangle", pointsForRectangle);
  rectang.displayInfo();

  Quadrangle quadrang(pointsForQuadrangle);
  quadrang.displayInfo();

  Circle circ(radius);
  circ.displayInfo();

  Ellipse ellip(a, b);
//  ellip.displayInfo();

  Shape *p = &ellip;
  std::cout << p->area();

  return 0;
}
